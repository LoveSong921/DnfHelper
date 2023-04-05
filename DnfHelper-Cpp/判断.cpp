#include "判断.h"
#include "读写.h"
#include "Call.h"
#include "基址.h"
#include "公用.h"

INT 解密(INT64 数据指针)
{
	INT64 temp = 读长整数型(数据指针);
	return (INT)temp;
}

VOID 加密(INT64 数据指针, INT 修改数值)
{
	INT64 temp;
	temp = 修改数值;
	写长整数型(数据指针, temp);
}

// 0选角 1城镇 2选图 3图内 5选择频道
INT 取游戏状态()
{
	return 读整数型(游戏状态);
}

BOOL 取是否城镇()
{
	if (读长整数型(读长整数型(取人物基质()) + 地图偏移) == 0)
	{
		return true;
	}
	return false;
}

BOOL 取是否开门()
{
	if (解密(读长整数型(读长整数型(读长整数型(取人物基质()) + 地图偏移) + 16) + 是否开门) == 0)
	{
		return true;
	}
	return false;
}

BOOL 判断_是否对话()
{
	if (读长整数型(对话基址) == 1 && 读长整数型(对话基址B) != 0 && 读长整数型(Esc对话基址) != 0)
	{
		return true;
	}
	return false;
}

BOOL 取是否BOSS房()
{
	坐标 当前 = 取当前房间();
	坐标 BOSS = 取BOSS房间();
	if (当前.x == BOSS.x && 当前.y == BOSS.y)
	{
		return true;
	}
	return false;
}

BOOL 取是否通关()
{
	INT64 房间数据 = 读长整数型(读长整数型(读长整数型(房间编号) + 时间基址) + 门型偏移);
	int 判断数值 = 读整数型(房间数据 + 篝火判断);
	if (判断数值 == 2 || 判断数值 == 0)
	{
		return true;
	}
	return false;
}

坐标 取BOSS房间()
{
	坐标 返回数据;
	INT64 房间数据 = 读长整数型(读长整数型(读长整数型(房间编号) + 时间基址) + 门型偏移);
	返回数据.x = 解密(房间数据 + BOSS房间X);
	返回数据.y = 解密(房间数据 + BOSS房间Y);
	return 返回数据;
}

坐标 取当前房间()
{
	坐标 返回数据;
	INT64 房间数据 = 读长整数型(读长整数型(读长整数型(房间编号) + 时间基址) + 门型偏移);
	返回数据.x = 读整数型(房间数据 + 当前房间X);
	返回数据.y = 读整数型(房间数据 + 当前房间Y);
	return 返回数据;
}

INT 取地图编号()
{
	return 读整数型(副本编号);
}

INT 取疲劳值()
{
	return 解密(最大疲劳) - 解密(当前疲劳);
}

INT 取角色等级() {
	return 读整数型(角色等级);
}

string 取地图名称()
{
	INT64 房间数据 = 读长整数型(读长整数型(读长整数型(房间编号) + 时间基址) + 门型偏移);
	return UnicodeToAnsi(读字节数组(读长整数型(房间数据 + 地图名称), 52));
}

INT 等级地图()
{
	int 局_角色等级 = 取角色等级();
	if (局_角色等级 <= 17)
	{
		if (局_角色等级 <= 3)
			return (3);//幽暗密林
		if (局_角色等级 <= 5)
			return (5);//雷鸣废墟
		if (局_角色等级 <= 8)
			return (6);//猛毒雷鸣废墟
		if (局_角色等级 <= 11)
			return (9);//冰霜幽暗密林
		if (局_角色等级 <= 13)
			return (7);//格拉卡
		if (局_角色等级 <= 15)
			return (8);//烈焰格拉卡
		if (局_角色等级 <= 17)
			return (1000);//暗黑雷鸣废墟
	}
	else if (局_角色等级 <= 23)
	{
		if (局_角色等级 <= 18)
			return (10);//龙人之塔
		if (局_角色等级 <= 19)
			return (12);//人偶玄关
		if (局_角色等级 <= 20)
			return (13);//石巨人塔
		if (局_角色等级 <= 21)
			return (14);//黑暗玄廊
		if (局_角色等级 <= 22)
			return (17);//城主宫殿
		if (局_角色等级 <= 23)
			return (15);//悬空城
	}
	else if (局_角色等级 <= 29)
	{
		if (局_角色等级 <= 24)
			return (17);//神殿外围
		if (局_角色等级 <= 25)
			return (22);//树精丛林
		if (局_角色等级 <= 26)
			return (23);//炼狱
		if (局_角色等级 <= 27)
			return (24);//极昼
		if (局_角色等级 <= 28)
			return (25);//第一脊椎
		if (局_角色等级 <= 29)
			return (26);//第二脊椎
	}
	else if (局_角色等级 <= 35)
	{
		if (局_角色等级 <= 30)
			return (27);//浅栖之地
		if (局_角色等级 <= 31)
			return (32);//蜘蛛洞穴
		if (局_角色等级 <= 32)
			return (150);//蜘蛛王国
		if (局_角色等级 <= 33)
			return (151);//英雄冢
		if (局_角色等级 <= 34)
			return (35);//暗精灵墓地
		if (局_角色等级 <= 35)
			return (34);//熔岩穴
	}
	else if (局_角色等级 <= 39)
	{
		if (局_角色等级 <= 36)
			return (152);//暴君的祭坛
		if (局_角色等级 <= 37)
			return (153);//黄金矿洞
		if (局_角色等级 <= 38)
			return (154);//远古墓穴深处
		if (局_角色等级 <= 39)
			return (154);//远古墓穴深处
	}
	else if (局_角色等级 <= 45)
	{
		if (局_角色等级 <= 40)
			return (40);//山脊
		if (局_角色等级 <= 41)
			return (41);//冰心少年
		if (局_角色等级 <= 42)
			return (42);//利库天井
		if (局_角色等级 <= 44)
			return (43);//白色废墟
		if (局_角色等级 <= 45)
			return (141);//布万加的修炼场
	}
	else if (局_角色等级 <= 49)
	{
		if (局_角色等级 <= 46)
			return (141);//绿都格罗兹尼
		if (局_角色等级 <= 47)
			return (50);//堕落的盗贼
		if (局_角色等级 <= 48)
			return (50);//堕落的盗贼
		if (局_角色等级 <= 49)
			return (52);//血蝴蝶之舞
	}
	else if (局_角色等级 <= 53)
	{
		if (局_角色等级 <= 50)
			return (52);//血蝴蝶之舞
		if (局_角色等级 <= 51)
			return (145);//冰晶森林
		if (局_角色等级 <= 52)
			return (145);//水晶矿脉
		if (局_角色等级 <= 53)
			return (148);//水晶矿脉
	}
	else if (局_角色等级 <= 58)
	{
		if (局_角色等级 <= 54)
			return (148);//蘑菇庄园
		if (局_角色等级 <= 55)
			return (148);//蚁后的巢穴
		if (局_角色等级 <= 56)
			return (158);//腐烂之地
		if (局_角色等级 <= 57)
			return (159);//赫顿玛尔旧街区
		if (局_角色等级 <= 58)
			return (159);//赫顿玛尔旧街区
	}
	else if (局_角色等级 <= 62)
	{
		if (局_角色等级 <= 59)
			return (161);//人鱼国度
		if (局_角色等级 <= 58)
			return (161);//鲨鱼栖息地
		if (局_角色等级 <= 60)
			return (163);//GBL女神殿
		if (局_角色等级 <= 61)
			return (164);//树精繁殖地
		if (局_角色等级 <= 62)
			return (164);//树精繁殖地
	}
	else if (局_角色等级 <= 70)
	{
		if (局_角色等级 <= 63)
			return (80);//根特外围
		if (局_角色等级 <= 64)
			return (81);//根特东门
		if (局_角色等级 <= 65)
			return (82);//根特南门
		if (局_角色等级 <= 66)
			return (83);//夜间袭击战
		if (局_角色等级 <= 67)
			return (84);//补给线阻断战
		if (局_角色等级 <= 68)
			return (85);//追击歼灭战
		if (局_角色等级 <= 69)
			return (85);//根特防御战
		if (局_角色等级 <= 70)
			return (85);//哈尔特山
	}
	else if (局_角色等级 <= 74)
	{
		if (局_角色等级 <= 71)
			return (86);//列车上的海贼
		if (局_角色等级 <= 72)
			return (87);//夺回西部线
		if (局_角色等级 <= 73)
			return (92);//雾都赫伊斯
		if (局_角色等级 <= 74)
			return (93);//阿登高地
	}
	else if (局_角色等级 <= 80)
	{
		if (局_角色等级 <= 75)
			return (93);//阿登高地
		if (局_角色等级 <= 76)
			return (70);//格兰之火
		if (局_角色等级 <= 77)
			return (71);//瘟疫之源
		if (局_角色等级 <= 78)
			return (72);//卡勒特之初
		if (局_角色等级 <= 79)
			return (74);//绝密区域
		if (局_角色等级 <= 80)
			return (76);//凛冬
	}
	else if (局_角色等级 <= 86)
	{
		if (局_角色等级 <= 80)
			return (76);//克雷发电站
		if (局_角色等级 <= 81)
			return (102);//普鲁兹发电站
		if (局_角色等级 <= 82)
			return (103);//特伦斯发电站
		if (局_角色等级 <= 85)
			return (104);//格蓝迪发电站
		if (局_角色等级 <= 86)
			return (104);//格蓝迪发电站
	}
	else if (局_角色等级 <= 91)
	{
		if (局_角色等级 <= 87)
			return (192);//钢铁之臂
		if (局_角色等级 <= 88)
			return (192);//钢铁之臂
		if (局_角色等级 <= 89)
			return (194);//光之舞会
		if (局_角色等级 <= 90)
			return (194);//光之舞会
		if (局_角色等级 <= 91)
			return (314);//红色魔女之森
	}
	else if (局_角色等级 <= 95)
	{
		if (局_角色等级 <= 92)
			return (291100268);//亡命杀镇
		if (局_角色等级 <= 93)
			return (291100268);//亡命杀镇
		if (局_角色等级 <= 94)
			return (291100293);//全蚀市场
		if (局_角色等级 <= 95)
			return (291100293);//全蚀市场
	}
	else if (局_角色等级 <= 100)
	{
		if (局_角色等级 <= 96)
			return (100000002);//根特皇宫
		if (局_角色等级 <= 97)
			return (100000002);//根特皇宫
		if (局_角色等级 <= 98)
			return (100000176);//无底坑道
		if (局_角色等级 <= 99)
			return (100000178);//无底坑道
		if (局_角色等级 <= 100)
			return (100000179);//暗黑神殿
	}
	return (1);
}