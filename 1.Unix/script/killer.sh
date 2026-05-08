var=$(ps | grep ft_script | grep -v grep | cut -d ' ' -f1)
kill $var