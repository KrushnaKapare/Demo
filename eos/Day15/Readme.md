1. Linux system call - Tasks

   - Linux do not much discriminate between processes and threads.
   - Both are referred as "task"
     - struct task_struct is created for both process/threads.
     - When we create a new process (like fork()), it creates a new task_struct (for child process) and it copies information about the resources (like ofdt, page tables, ipc info, ...). It also updates information about new resources.
     - When we create a new thread (like pthread_create()), it creates a new task_struct (for new thread) and all resources info (like ofdt, page tables, ipc info, ...) is shared with the parent process.
   - In Linux, when a new process is created a new task_struct is created. It is same for the process as well as its main thread.
   - Linux have common system to create process or thread -- clone().

   - Process can be seen as a new task that doesn't share (it copies) any section with parent task, but sends SIGCHLD signal to the parent upon its termination.
     ```C
     child_task_id = clone(task_fn, stack, SIGCHLD, NULL);
     ```
   - Thread can be seen as a new task that shares parent's virtual address space, open files, fs and signal handler table.
     ```C
     child_task_id = clone(task_fn, stack, CLONE_VM|CLONE_FILES|CLONE_FS|CLONE_SIGHAND, NULL);
     ```

2. Threading model

   - User Thread
     - Created by thread library (like pthread) in user space
     - Managed by the library (may be with a mini-scheduler in library)
     - For this thread library may create threads into kernel (using system calls). Referred as "Light weight process".
   - Kernel Thread
     - Created by system calls (from kernel space implementation)
     - Managed/scheduled by the Kernel CPU scheduler
   - Mapping between user threads and kernel threads is called as "Threading Model".

3. Kernel space Thread / Kernel Daemon

- We will discuss in device drivers.

4. Deadlock

- Refer notes & slides
