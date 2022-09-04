//打印导航相关界面
void print1();
//显示建筑标号函数
void print(int num,int school);
//得到导航的起止地点以及导航策略
void getOrder(int* sCampus,int* start,int* eCampus,int* end,int* type,int (*adress)[20]);
//得到数字对应的建筑物名称
void Num_to_Name(int school,int number,char* name); 
//将方向输出为文字
void direction_to_Name(int number,char* name); 
