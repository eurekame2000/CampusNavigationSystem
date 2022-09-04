#include<stdio.h>
#define bus1 1//校区1公交站点编号 
#define schoolbus1 0//校区1班车站点编号 
#define bus2 0//校区2公交站点编号 
#define schoolbus2 15//校区2班车站点编号 
#define bus -3//公交站点策略标志 
#define schoolbus -2//班车站点策略标志 
#define wspeed 100//理想步行速度
#define bspeed 200//自行车骑行速度
#define infi  999999//距离上限，表示两点间无路径
#define buscost 30//公交车在校区间通行所需时间
#define schoolbuscost 20 //校车在校区间同行所需时间
void initialize();
