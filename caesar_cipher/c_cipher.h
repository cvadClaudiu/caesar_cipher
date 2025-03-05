#pragma once

#include <string>
#include <limits>

namespace caesarciphergui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class caesar : public System::Windows::Forms::Form
	{
	public:
		caesar(void)
		{
			InitializeComponent();
		}

	protected:
		~caesar()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		wchar_t EncryptChar(wchar_t ch, int key)
		{
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			{
				if (ch >= 'A' && ch <= 'Z')
					return 'A' + ((ch - 'A') + key) % 26;
				else
					return 'a' + ((ch - 'a') + key) % 26;
			}
			return ch;
		}

		wchar_t DecryptChar(wchar_t ch, int key)
		{
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			{
				if (ch >= 'A' && ch <= 'Z')
					return 'A' + ((ch - 'A') - key + 26) % 26;
				else
					return 'a' + ((ch - 'a') - key + 26) % 26;
			}
			return ch;
		}

		String^ Encrypt(String^ text, int key)
		{
			String^ result = "";
			for each (wchar_t ch in text)
			{
				result += EncryptChar(ch, key);
			}
			return result;
		}

		String^ Decrypt(String^ text, int key)
		{
			String^ result = "";
			for each (wchar_t ch in text)
			{
				result += DecryptChar(ch, key);
			}
			return result;
		}

		bool ValidateKey(int key)
		{
			return key >= 1 && key <= 25;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button01 = (gcnew System::Windows::Forms::Button());
			this->button02 = (gcnew System::Windows::Forms::Button());
			this->input_text = (gcnew System::Windows::Forms::TextBox());
			this->output_text = (gcnew System::Windows::Forms::TextBox());
			this->cheie = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button01
			// 
			this->button01->Location = System::Drawing::Point(21, 204);
			this->button01->Name = L"button01";
			this->button01->Size = System::Drawing::Size(116, 66);
			this->button01->TabIndex = 3;
			this->button01->Text = L"Encrypt";
			this->button01->UseVisualStyleBackColor = true;
			this->button01->Click += gcnew System::EventHandler(this, &caesar::OnEncryptClick);
			// 
			// button02
			// 
			this->button02->Location = System::Drawing::Point(167, 206);
			this->button02->Name = L"button02";
			this->button02->Size = System::Drawing::Size(116, 62);
			this->button02->TabIndex = 4;
			this->button02->Text = L"Decrypt";
			this->button02->UseVisualStyleBackColor = true;
			this->button02->Click += gcnew System::EventHandler(this, &caesar::OnDecryptClick);
			// 
			// input_text
			// 
			this->input_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->input_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_text->Location = System::Drawing::Point(21, 12);
			this->input_text->Multiline = true;
			this->input_text->Name = L"input_text";
			this->input_text->Size = System::Drawing::Size(523, 90);
			this->input_text->TabIndex = 1;
			this->input_text->TextChanged += gcnew System::EventHandler(this, &caesar::inputText_TextChanged);
			// 
			// output_text
			// 
			this->output_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->output_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_text->Location = System::Drawing::Point(21, 319);
			this->output_text->Multiline = true;
			this->output_text->Name = L"output_text";
			this->output_text->Size = System::Drawing::Size(523, 90);
			this->output_text->TabIndex = 5;
			this->output_text->TextChanged += gcnew System::EventHandler(this, &caesar::output_text_TextChanged);
			// 
			// cheie
			// 
			this->cheie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cheie->Location = System::Drawing::Point(21, 137);
			this->cheie->Multiline = true;
			this->cheie->Name = L"cheie";
			this->cheie->Size = System::Drawing::Size(116, 61);
			this->cheie->TabIndex = 2;
			this->cheie->Text = L"Key";
			// 
			// caesar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 466);
			this->Controls->Add(this->cheie);
			this->Controls->Add(this->output_text);
			this->Controls->Add(this->input_text);
			this->Controls->Add(this->button02);
			this->Controls->Add(this->button01);
			this->Name = L"caesar";
			this->Text = L"Caesar Cipher";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void OnEncryptClick(System::Object^ sender, System::EventArgs^ e) {
			try {
				int key = Convert::ToInt32(cheie->Text);

				if (!ValidateKey(key)) {
					MessageBox::Show("Invalid key. Must be between 1 and 25.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				String^ originalText = input_text->Text;
				output_text->Text = Encrypt(originalText, key);
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter a valid numeric key.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	private:
		System::Void OnDecryptClick(System::Object^ sender, System::EventArgs^ e) {
			try {
				int key = Convert::ToInt32(cheie->Text);

				if (!ValidateKey(key)) {
					MessageBox::Show("Invalid key. Must be between 1 and 25.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				String^ originalText = input_text->Text;
				output_text->Text = Decrypt(originalText, key);
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter a valid numeric key.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
private: System::Windows::Forms::Button^ button01;
private: System::Windows::Forms::Button^ button02;

	private:


private: System::Windows::Forms::TextBox^ input_text;
private: System::Windows::Forms::TextBox^ output_text;


private: System::Windows::Forms::TextBox^ cheie;

		System::ComponentModel::Container^ components;
	private: System::Void inputText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void output_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}