data_example = open("./day4_input_example.txt").read()
data_test = open("./day4_input_test_part2.txt").read()
data = open("./day4_input.txt").read()

m_example = []
for line in data_example.split('\n'):
  if len(line)!=0 : m_example.append(list(line))

m = []
for line in data.split('\n'):
  if len(line)!=0 : m.append(list(line))

print("--- Part Two ---")
m_test = []
for line in data_test.split('\n'):
   if len(line)!=0 : m_test.append(list(line))

def x_mas_cnt(m, print_fl = 0):
    x = [[[-1,-1], [1,-1], [-1, 1], [1, 1]],
         [[-1,-1], [-1,1], [1, -1], [1, 1]],
         [[-1, 1], [1, 1], [-1,-1], [1,-1], ],
         [[1, -1], [1, 1], [-1,-1], [-1,1], ],
         ]
    x_mas_cnt = 0
    for i in range(1, len(m)-1):
        for j in range(1, len(m[i])-1):
            if (m[i][j] == 'A'):
                for x_ij in x:
                    if (m[i+x_ij[0][0]][j+x_ij[0][1]] == 'M' and m[i+x_ij[1][0]][j+x_ij[1][1]] == 'M' and
                        m[i+x_ij[2][0]][j+x_ij[2][1]] == 'S' and m[i+x_ij[3][0]][j+x_ij[3][1]] == 'S'):
                        x_mas_cnt += 1

    return x_mas_cnt

print("x_mas_cnt(m_test_part2): ", x_mas_cnt(m_test))
print("x_mas_cnt(m_example): ", x_mas_cnt(m_example))
print("x_mas_cnt(m): ", x_mas_cnt(m))
