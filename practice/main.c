#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char name[32];
	int life, attack, defense, magic;
} param;

void act(param* actor, param* target, int command)
{
	int point;
	switch (command)
	{
	case 0:
		point = actor->attack - target->defense;
		target->life -= point;
		printf("%sの攻撃! %s に%d のダメージを与えた!\n", actor->name, target->name, point);
		break;
	case 1:
		point = 20;
		actor->attack += point;
		printf("%s は力を溜めている。 %s は %d 力が溜まった!\n", actor->name, actor->name, point);
		break;
	case 2:
		point = 50;
		actor->life += point;
		printf("%s は回復を唱えた。 %s の Lifeが %d 回復した!\n", actor->name, actor->name, point);
		break;
	case 3:
		point = actor->magic;
		target->life -= point;
		printf("%sのファイア! %s に%d のダメージを与えた!\n", actor->name, target->name, point);
		/* 違う数字を入力したら無視されて次のターンになってしまう */
	}
}

int GetRandom(int min, int max);

int main(void)
{
	param you = { "学生", 100, 100, 50, 100 };    
	param enemy = { "教授", 100, 60, 50, 10 };
	printf("%sが現れた!\n", enemy.name);
	for (; ;)             
	{
		int command;
		printf("%s: Life = %d, Attack = %d, Defense = %d\n", you.name, you.life, you.attack, you.defense);
		printf("%s: Life = %d, Attack = %d, Defense = %d\n", enemy.name, enemy.life, enemy.attack, enemy.defense);
		printf("(0) 攻撃\n(1) 攻撃アップ\n(2) 回復魔法\n(3) 攻撃魔法\n");
		printf("Command:");
		scanf("%d", &command);
		if (command < 0 || command > 3)
		{
			printf("『0~3のコマンドを入力するのだ』\n");
		}
		act(&you, &enemy, command);
		if (enemy.life <= 0)
		{
			printf("%s を倒した!\n", enemy.name);
			return 0;
		}

		act(&enemy, &you, GetRandom(1, 3));
		if (you.life <= 0)
		{
			printf("%s は倒れた...\n", you.name);
			return 0;
		}
	}
}

int GetRandom(int min, int max)
{
	srand((unsigned int)time(NULL));

	return rand() % 4;  /* 0〜3の乱数を発生させる */
}