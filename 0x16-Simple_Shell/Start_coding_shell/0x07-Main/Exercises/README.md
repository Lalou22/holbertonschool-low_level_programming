# Excersise
## 0. printenv with environ
Write a program that prints the environment using the global variable `environ`.
<br>
## 1. env vs environ
Write a program that prints the address of `env` (the third parameter of the `main` function) and `environ` (the global variable). Are they they same? Does this make sense?
<br>
## 2. getenv()
Write a function that gets an environment variable. (without using `getenv`)
- Prototype: `char *_getenv(const char *name);`
<br>man 3 `getenv`
<br>
## 3. PATH
Write a function that prints each directory contained in the the environment variable `PATH`, one directory per line.
<br>
## 4. PATH
Write a function that builds a linked list of the `PATH` directories.
<br>
## 5. setenv
Write a function that changes or adds an environment variable (without using `setenv`).
- Prototype: `int _setenv(const char *name, const char *value, int overwrite);`
<br>man 3 `setenv`
<br>
## 6. unsetenv
Write a function that deletes the variable name from the environment (without using `unsetenv`).
- Prototype: `int _unsetenv(const char *name);`
<br>man 3 `unsetenv`
<br>

