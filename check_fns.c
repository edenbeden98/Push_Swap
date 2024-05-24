
/*
bool	check_duplicates(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv
	}
}
*/
bool	check_all_integers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_int_size(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_input(int argc, char **argv)
{
//	if (check_duplicates(argc, argv))
//		return (false);
	if (!check_all_integers(argc, argv))
		return (false);
//	if (!check_int_size(argc, argv))
//		return (false);
	return (true);
}

