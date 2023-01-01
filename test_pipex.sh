# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_pipex.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 13:25:34 by tfujiwar          #+#    #+#              #
#    Updated: 2022/12/13 13:56:35 by tfujiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f in.txt out.txt shell_out.txt pipex_out.txt

# test when in_file doesn't exist
# check if the errorcode is equal to set number(4)
echo "===== ./pipex in.txt cat wc out.txt (in.txt: doesn't exist) ====="
./pipex in.txt cat wc out.txt
if [ $? -eq 4 ]; then
	echo "OK"
else
	echo "NG"
fi

# test in redirect case
echo hello, world > in.txt

echo "===== ./pipex in.txt cat wc out.txt (in.txt: \"hello, world\") ====="
./pipex in.txt cat wc pipex_out.txt
cat < in.txt | wc > shell_out.txt
d=`diff pipex_out.txt shell_out.txt | wc -l`
if [ $d -eq 0 ]; then
	echo "OK"
else
	echo "NG"
fi

# test in heredoc case
echo "===== ./pipex here_doc in.txt cat wc out.txt (in.txt: \"hello, world\") ====="
echo "enter hello, world & EOF for here_doc (pipex)"
./pipex here_doc EOF in.txt cat wc pipex_out.txt
cat << EOF | wc >> shell_out.txt
hello, world
EOF
d=`diff pipex_out.txt shell_out.txt | wc -l`
if [ $d -eq 0 ]; then
	echo "OK"
else
	echo "NG"
fi