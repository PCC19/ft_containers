	rm -f vv1 vv2 
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a 2> vv1
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a_stl 2> vv2
	vimdiff vv1 vv2
