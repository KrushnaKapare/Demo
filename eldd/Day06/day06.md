### Simple File Copy Program

- Without Error Checking

```C
fs = open("src", O_RDONLY);
fd = open("dest", O_WRONLY | O_CREAT | O_TRUNC, 0600);
while((cnt = read(fs, buf, sizeof(buf))) != 0)
    write(fd, buf, cnt);
close(fd);
close(fs);
```

- With all Error Checking

```C
fs = open("src", O_RDONLY);
if(fs < 0) {
    perror("failed to open src file");
    _exit(1);
}
fd = open("dest", O_WRONLY | O_CREAT | O_TRUNC, 0600);
if(fd < 0) {
    perror("failed to open dest file");
    close(fs);
    _exit(2);
}
while((cnt = read(fs, buf, sizeof(buf))) != 0) {
    if(cnt < 0) {
        perror("failed to read src file");
        close(fd);
        close(fs);
        _exit(3);
    }
    ret = write(fd, buf, cnt);
    if(ret < 0) {
        perror("failed to write dest file");
        close(fd);
        close(fs);
        _exit(4);
    }
}
close(fd);
close(fs);
```

### Pseudo Char Device Driver

- Step 1: Write a basic kernel module -- init() & exit()
- Step 2: Pseudo device -- char buffer[32];
- Step 3:
