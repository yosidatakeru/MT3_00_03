#include <Novice.h>
#include<Vector3AndMatrix.h>
#include<Function.h>
const char kWindowTitle[] = "LE2B_29_ヨシダタケル";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void MatrixScreenPrintf(int x, int y, Matrix4x4 matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

void VectorScreenPrintf(int x, int y, Vector3 vector) 
{
	Novice::ScreenPrintf(x, y,"%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
    Novice::ScreenPrintf(x + kColumnWidth+ kColumnWidth, y , "%.02f", vector.z);
}

//Vector3 ToScreen(const Vector3* world) {
//	const Vector3 kWorldToScreenTranslate = { 0.0f, 500.0f };
//	const Vector3 kWorldToScreenScale = { 1.0f, -1.0f };
//	return{
//
//		(world->x * kWorldToScreenScale.x) + kWorldToScreenTranslate.x,
//		(world->y * kWorldToScreenScale.y) + kWorldToScreenTranslate.y ,
//		(world->y * kWorldToScreenScale.z) + kWorldToScreenTranslate.z };
//
//}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector3 translate{ 4.1f,2.6f,0.8f };
	Vector3 scale{ 1.5f,5.2f,7.3f };
	
	Vector3 point{ 2.3f,3.8f,1.4f };
	
	Matrix4x4 trnsformMatrix =
	{
	1.0f,2.0f,3.0f,4.0f,
	3.0f,1.0f,1.0f,2.0f,
	1.0f,4.0f,2.0f,3.0f,
	2.0f,2.0f,1.0f,3.0f
	};
	Vector3 trnsformed = Transform(point, trnsformMatrix);
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
	Matrix4x4 scalematrix = MakeeScaleMatrix(scale);
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
	
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPrintf(0, 0, trnsformed);
		MatrixScreenPrintf(0, 30, translateMatrix);
		MatrixScreenPrintf(0, 120, scalematrix);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
