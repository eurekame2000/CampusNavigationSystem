/////相关全局变量 
int locate1[20][2];//存校区1的x,y坐标
int locate2[20][2];//存校区2的x,y坐标
int distance1[80][80];//存校区1的距离矩阵
int  distance2[80][80];//存校区2的距离矩阵
char direction1[80][80];//存校区1的道路方向矩阵
char direction2[80][80];//存校区2的道路方向矩阵 
int bikeway1[80][80];//自行车道
int bikeway2[80][80];
float crowded1[80][80];//拥挤度
float crowded2[80][80];
int wdistance[2][80][80];//处理后的距离矩阵
int bdistance[2][80][80];//考虑自行车道且经处理后的距离矩阵
int equidis2[2][80][80];//考虑拥挤度再经过Floyd处理后的等同距离矩阵
int equidis4[2][80][80];//考虑拥挤度和自行车道再经过Floyd处理后的等同距离矩阵
int path2[2][80][80];//策略2路径矩阵
int path4[2][80][80];//策略4路径矩阵

//判断输入的序号是否符合规定，若不符合再次输入 
void judge(int* num,int sign);


