#include "Enemy_Mng.hpp"


//コンストラクタ
Enemy_Mng::Enemy_Mng()
{
	Handle = LoadGraph("Assets/Enemy.png");

	enemy = std::make_shared<std::vector<Enemy>>();

	enemy->push_back(Enemy(Handle));	//追加
}


//エネミーを返す
std::shared_ptr<std::vector<Enemy>> Enemy_Mng::getEnemy()
{
	return enemy;
}

//プレイヤーとの当たり判定
void Enemy_Mng::ColPlayer(Player& player)
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		//交差判定
		if (Box_Collision::Intersect(itr->mCol, player.mCol) == true)
		{
			itr->FixPos(player.getPosition());
		}
	}

}

//バレットとの当たり判定
void Enemy_Mng::ColBullet(std::shared_ptr<std::vector<Bullet>> bullet)
{

}


//更新
void Enemy_Mng::Update()
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		itr->Update();
	}

}

//描画
void Enemy_Mng::Draw()
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		itr->Draw();
	}
}



//デストラクタ
Enemy_Mng::~Enemy_Mng()
{

}
