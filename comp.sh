#./a >> out1; ./a_stl >> out2; diff -y out1 out2
rm -f out1 out2
./a >> out1; ./a_stl >> out2; vimdiff out1 out2
