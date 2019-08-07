#pragma once

namespace void포인터뿌잉 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// 보이드에 대한 요약입니다.
	/// </summary>
	public ref class 보이드 : public System::Windows::Forms::Form
	{
	public:
		보이드(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~보이드()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다.
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// 보이드
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"보이드";
			this->Text = L"보이드";
			this->Load += gcnew System::EventHandler(this, &보이드::보이드_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void 보이드_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
