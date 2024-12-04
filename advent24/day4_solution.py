data_example = open("./day4_input_example.txt").read()
data_test_part1 = open("./day4_input_test_part1.txt").read()
data_test_part2 = open("./day4_input_test_part2.txt").read()
data = open("./day4_input.txt").read()

m_example = []
for line in data_example.split('\n'):
  if len(line)!=0 : m_example.append(list(line))
  
m_test_part1 = []
for line in data_test_part1.split('\n'):
   if len(line)!=0 : m_test_part1.append(list(line))
  
m = []
for line in data.split('\n'):
   if len(line)!=0 : m.append(list(line))

print("--- Part One ---")
def xmas_cnt(m, print_fl = 0):
    xmas_len = len("XMAS")-1
    xmas_cnt = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            if (m[i][j] == 'X'):
                # if print_fl: print("X (i,j): (", i, ",", j, ")")
                ## horizontal
                # horizontal j+
                if (j < len(m[i])-(xmas_len)):
                    if ("M" == m[i][j+1] and "A" == m[i][j+2] and "S" == m[i][j+3]):
                        if print_fl: print("XMAS h+ (i,j+): (", i, ",", j, ")")
                        xmas_cnt+=1
                # horizontal j-
                if (j >= xmas_len):
                    if ("M" == m[i][j-1] and "A" == m[i][j-2] and "S" == m[i][j-3]):
                        if print_fl: print("XMAS h- (i,j-): (", i, ",", j, ")")
                        xmas_cnt+=1

                ## vertical
                # vertical i+
                if (i < len(m)-(xmas_len)):
                    if ("M" == m[i+1][j] and "A" == m[i+2][j] and "S" == m[i+3][j]):
                        if print_fl: print("XMAS v+ (i+,j): (", i, ",", j, ")")
                        xmas_cnt+=1
                # vertical i-
                if (i >= xmas_len):
                    if ("M" == m[i-1][j] and "A" == m[i-2][j] and "S" == m[i-3][j]):
                        if print_fl: print("XMAS v- (i-,j): (", i, ",", j, ")")
                        xmas_cnt+=1

                ## diagonal
                # diagonal i+, j+
                if (i < len(m)-(xmas_len) and j < len(m[i])-(xmas_len)):
                    # if print_fl: print("(",i+1, "," , j+1, ") (", "(",i+2, "," , j+2, ") (", "(",i+3, "," , j+3, ")")
                    if ("M" == m[i+1][j+1] and "A" == m[i+2][j+2] and "S" == m[i+3][j+3]):
                        if print_fl: print("XMAS d++ (i+,j+): (", i, ",", j, ")")
                        xmas_cnt+=1
                # diagonal i+, j-
                if (i < len(m)-(xmas_len) and j >= xmas_len):
                    if ("M" == m[i+1][j-1] and "A" == m[i+2][j-2] and "S" == m[i+3][j-3]):
                        if print_fl: print("XMAS d+- (i+,j-): (", i, ",", j, ")")
                        xmas_cnt+=1
                # diagonal i-, j+
                if (i >= xmas_len and j < len(m[i])-(xmas_len)):
                    if ("M" == m[i-1][j+1] and "A" == m[i-2][j+2] and "S" == m[i-3][j+3]):
                        if print_fl: print("XMAS d-+ (i-,j+): (", i, ",", j, ")")
                        xmas_cnt+=1
                # diagonal i-, j-
                if (i >= xmas_len and j >= xmas_len):
                    if ("M" == m[i-1][j-1] and "A" == m[i-2][j-2] and "S" == m[i-3][j-3]):
                        if print_fl: print("XMAS d-- (i+,j-): (", i, ",", j, ")")
                        xmas_cnt+=1
    return xmas_cnt

print("xmas_cnt(m_test): ", xmas_cnt(m_test_part1))
print("xmas_cnt(m_example): ", xmas_cnt(m_example))
print("xmas_cnt(m_test): ", xmas_cnt(m))

print("--- Part Two ---")
m_test_part2 = []
for line in data_test_part2.split('\n'):
   if len(line)!=0 : m_test_part2.append(list(line))

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

print("x_mas_cnt(m_test_part2): ", x_mas_cnt(m_test_part2))
print("x_mas_cnt(m_example): ", x_mas_cnt(m_example))
print("x_mas_cnt(m_test): ", x_mas_cnt(m))
