0.  Mutex
    - Mutex = Mutual Exclusion
    - Thread locking mutex become owner of the mutex. Only owner can unlock the mutex.
    - If a thread try to lock the mutex that is already locked by another thread, the locking thread is blocked (waiting state) until the mutex is unlocked by the owner thread.

1.  Mutex -- Types

        - pthread_mutex_t m;
        - pthread_mutex_init(&m, NULL);
          - NULL - default mutex attributes
        - pthread_mutex_destroy(&m);
        - pthread_mutex_lock(&m);
        - pthread_mutex_unlock(&m);

        - Mutex behaviour depends on mutex type.
          A. NORMAL - A thread relocking the same mutex - will cause the deadlock i.e. the thread is permanently blocked.
          `       thread1 --
          lock(m);
          lock(m);    -- thread1 blocked

    ` - A thread trying to unlock the mutex that is locked by other thread - results in undefined behavior

    ````
    thread1 --
    lock(m);
            thread2 --
                unlock(m);  -- undefined behavior
            ```
    B. ERRCHECK - - A thread relocking the same mutex - will cause the error and return -ve error code.
    ` thread1 --
    lock(m);
    lock(m); -- returns error
    ` - A thread trying to unlock the mutex that is locked by other thread - will cause the error and returns -ve error code
    ````

    thread1 --
    lock(m);
    thread2 --
    unlock(m); -- returns error
    ```C. RECURSIVE - A thread relocking the same mutex - will increase internal lock count. - The mutex will be unlocked only when it unlocked same number of times (it was locked.)` thread1 --
    lock(m) -- lock count=1
    lock(m) -- lock count=2
    lock(m) -- lock count=3
    ...
    use the resource
    ...
    unlock(m) -- lock count=2
    unlock(m) -- lock count=1
    unlock(m) -- lock count=0
    `

2.  Critical Section

    - Section of code which when executed by multiple threads at the same time, may cause unexpected/undesired results.
    - Programmer need to ensure that only one thread can execute the section at a time.
    - In Windows OS, CriticalSection sync object is used to solve this problem.
    - In Linux, the critical section problem is handled using mutex.

      ```
      mutex m;

      lock(m) -- at the start of critical section
      ...
      critical section
      ...
      unlock(m) -- at the end of critical section
      ```

3.  Condition variables

    - Problem -- INFOTECH should be printed after SUNBEAM
    - Solution using Semaphore
      - s = 0
      ```
      thread 1
          - print SUNBEAM
          - V(s)
          - ...
      ```
      ```
      thread 2
          - P(s)
          - print INFOTECH
      ```
    - Solution using Condition Variable
      - Problem 1 -- Only one string should print at a time.
        - Solution 1 -- use mutex
      - Problem 2 -- Start printing SUNBEAM first.
        - Solution 2 -- use cond var (with mutex)
      ```
      mutex m;
      cond_var c;
      flag = 0
      ```
      ```
      thread 1
          - lock(m)
          - print SUNBEAM
          - flag = 1
          - cond_signal(c)
          - unlock(m)
          - ...
      ```
      ```
      thread 2
          - lock(m)
          - while(!flag)
          -     cond_wait(m, c)
          - print INFOTECH
          - unlock(m)
      ```
    - cond_wait(m, c)
      - release associated mutex
      - block current thread on the cond var
      - after wakeup (upon signal from other thread),
        re-lock the mutex and resume execution.
    - cond_signal(c)
      - wakeup one of thread sleeping on cond var
    - cond_broadcast(c)
      - wakeup all the threads sleeping on cond var

4.  Synchronization Objects

    - UNIX: Semaphore
    - Linux (user-space - POSIX): Semaphore, Mutex, Condition Variable
    - Linux (kernel-space): Semaphore, Mutex, Spinlock
    - Windows: Semaphore, Mutex, Event, CriticalSection, WaitableTimer
    - FreeRTOS: SemaphoreCounting, SemaphoreBinary, SemaphoreMutex, CriticalSection

5.  Spinlock

    - Spinlock is hardware based Synchronization mechanism.
    - It uses bus locking instructions.
    - Only one process/processor can lock the spinlock at a time.
    - If it is already locked, the next process will keep polling for spinlock availability. It will be in running state.

6.  Thread termination
    - Thread is auto-terminated when thread function is completed.
      ```
      void* thread_func(void *param) {
        int i;
        for(i=1; i<=10; i++) {
          printf("incr: %d\n", i);
          sleep(1);
        }
        return NULL;
      }

      //in main()
      pthread_create(&th, NULL, thread_func, NULL)
        - this thread "th" will be auto-terminated after 10 secs of execution
      ```

    - Thread may terminate itself before completion of the thread_func() using pthread_exit() fn.
      ```
      void* thread_func(void *param) {
        int i;
        for(i=1; i<=10; i++) {
          printf("incr: %d\n", i);
          sleep(1);
          if(i == 5)
              pthread_exit(NULL);
        }
      }

      //in main()
      pthread_create(&th, NULL, thread_func, NULL)
        - this thread "th" will be auto-terminated after 10 secs of execution
      ```

    - Cancellation
      ```
      void* thread_func(void *param) {
        int i;
        for(i=1; i<=10; i++) {
          printf("incr: %d\n", i);
          sleep(1);
        }
        return NULL;
      }
      ```
      in main()
      ```
      pthread_create(&th, NULL, thread_func, NULL);
      sleep(4);
      pthread_cancel(th); // main thread sending cancellation request to thread.
        // the "th" will be terminated after receiving cancellation request on safe point
      ```

    - Signals
      ```
      void* thread_func(void *param) {
        int i;
        for(i=1; i<=10; i++) {
          printf("incr: %d\n", i);
          sleep(1);
        }
        return NULL;
      }
      ```
      signal handler
      ```
      void sigint_handler(int sig) {
        // executed by the thread to which signal was sent.
        // ...
      }
      ```
      in main()
      ```
      signal(SIGINT, sigint_handler);
        // signal handler is process-wide (not thread specific).
      pthread_create(&th, NULL, thread_func, NULL);
      sleep(4);
      pthread_kill(th, SIGINT);
      ```

  - When process is terminated, then all threads in that process are auto-terminated.

7. fork() in multi-threaded process
  - When a thread from a multi-threaded process calls fork() syscall, a new child process is created with single thread i.e. main thread of that child.
  - the new child continues to execute its parent "thread" code.

8.  Thread group/Process group
  - Thread group = Multi-threaded process
      - Multiple threads in the process are in a thread group.
      - Main thread is considered as thread group leader.
      - Main thread id --> Thread group id
      - cmd> ps -A -m -o pid,tgid,tid,nlwp,cmd
      - In single threaded process, the process group contains single thread i.e. main thread.

  - Process group = Shell command
      - e.g. cmd> cat file.txt | sort | uniq | wc
      - When a command internally creates multiple processes, then it is referred as a process group or job.
      - The first process in the group is considered as process group leader (e.g. cat process in above group of 4 processes).
      - First process id --> Process group id
      - cmd> ps -A -p pid,pgid,cmd
      - If a parent process (e.g. cmd> ./parent.out) internally creates multiple child processes (using fork()), then they all are in same process group. In this case, process group id = parent process id
  
  - Session = Shell
      - When multiple commands are executed in a shell, then they are considered as part of same session (started by the shell).
      - All these processes will have same session id.
      - Shell process (e.g. bash) id --> session id



