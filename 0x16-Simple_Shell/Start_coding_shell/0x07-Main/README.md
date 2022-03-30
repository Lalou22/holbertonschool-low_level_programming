# Main
So far we have seen that main could have different prototypes:
- `int main(void);`
- `int main(int ac, char **av);`
There is actually another prototype:
- `int main(int ac, char **av, char **env);`
Where env is a NULL terminated array of strings.

