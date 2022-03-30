# Main<br>
<br>
So far we have seen that main could have different prototypes:<br>
...
  int main(void);
  int main(int ac, char **av);
...
<br>
There is actually another prototype:<br>
...
  int main(int ac, char **av, char **env);
...
<br>
Where env is a NULL terminated array of strings.<br>
