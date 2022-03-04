#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int ac, char **av, char **env)
{
    char *cmd[]={" ", "-la",(char *)0};
  //  char *env_args[] = {(char*)0};
    char *str = "/bin/ls";
    execve(str, cmd, env);

}