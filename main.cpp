#include <Novice.h>
#include <Vector3Function.h>

const char kWindowTitle[] = "学籍番号";

const int kRowHeight = 20;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	/*Vector3* v1 = new Vector3(1.0f, 3.0f, -5.0f);
	Vector3* v2 = new Vector3(4.0f, -1.0f, 2.0f);*/

	Vector3 v1(1.0f, 3.0f, -5.0f);
	Vector3 v2(4.0f, -1.0f, 2.0f);
	float k = 4.0f;

	Vector3 resultAdd = v1 + v2;
	Vector3 resultSubtract = v1 - v2;
	Vector3 resultMultiply = k * v1;
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normailize(v2);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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

		VectorScreenPrintf(0, 0, resultAdd, ": Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, ": Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, ": Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%0.2f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%0.2f  : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, ": Normalize");


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
