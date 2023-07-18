typedef struct s_cmd {
    char    **cmd;
    char    **infile;
    char    **outfile;
    s_cmd   *prev;
    s_cmd   *next;
}           t_cmd;

int main (void)
{

    t_cmd   first_cmd;

    first_cmd.cmd = (char **)malloc(sizeof(char) * 3);
    first_cmd.cmd[0] = ft_strdup("cat"); // /usr/bin/cat
    if (ft_is_builtin(first_cmd.cmd[0]) && list_cmd.length == 1)
    {
        // pas fork
    }
    else if (ft_is_builtin(first_cmd.cmd[0]) && list_cmd.length > 1)
    {
        // fork
        // chercher path
        // faire le dup
        // 
    }
    {
        // 
    }
    first_cmd.cmd[1] = ft_strdup("-e");

}