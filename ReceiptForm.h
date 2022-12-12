#pragma once
#include <iostream>
#include <windows.h>
#include <Shlobj.h>
#include <fstream>

namespace POS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	namespace fs = std::experimental::filesystem;

	public ref class ReceiptForm : public System::Windows::Forms::Form {
	public:
		ReceiptForm(void)
		{
			InitializeComponent();
		}

	protected:
		~ReceiptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		System::Windows::Forms::SplitContainer^ splitContainer1;
		System::Windows::Forms::Button^ printButton;

		System::Windows::Forms::Button^ cancelButton;
		System::Windows::Forms::Label^ printLabel;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->printButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->printLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->splitContainer1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->printLabel, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(584, 361);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 183);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->printButton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->cancelButton);
			this->splitContainer1->Size = System::Drawing::Size(578, 175);
			this->splitContainer1->SplitterDistance = 289;
			this->splitContainer1->TabIndex = 0;
			// 
			// printButton
			// 
			this->printButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(104)));
			this->printButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->printButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printButton->Location = System::Drawing::Point(0, 0);
			this->printButton->Name = L"printButton";
			this->printButton->Size = System::Drawing::Size(289, 175);
			this->printButton->TabIndex = 0;
			this->printButton->Text = L"Print";
			this->printButton->UseVisualStyleBackColor = false;
			this->printButton->Click += gcnew System::EventHandler(this, &ReceiptForm::PrintButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->cancelButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(0, 0);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(285, 175);
			this->cancelButton->TabIndex = 0;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &ReceiptForm::CancelButton_Click);
			// 
			// printLabel
			// 
			this->printLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->printLabel->AutoSize = true;
			this->printLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printLabel->Location = System::Drawing::Point(3, 0);
			this->printLabel->Name = L"printLabel";
			this->printLabel->Size = System::Drawing::Size(578, 180);
			this->printLabel->TabIndex = 1;
			this->printLabel->Text = L"Print Receipt\?";
			this->printLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ReceiptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"ReceiptForm";
			this->Text = L"ReceiptForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void PrintButton_Click(System::Object^ sender, System::EventArgs^ e) {
			
			

			

			/*fstream receipt("receipt.txt");
			receipt.open("receipt.txt");

			fs::resize_file("receipt.txt", 0);
			receipt.seekp(0);
			double total;

			time_t now = time(0);
			tm* ltm = localtime(&now);

			receipt << "Date: " << ltm->tm_mday << " " << ltm->tm_mon + 1 << " " << ltm->tm_year + 1900 << endl;
			receipt << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl << endl;

			receipt << "Total Items:" << basket.size() << endl << endl;

			for (int i = 0; i < basket.size(); i++) {
				receipt << "Item: " + basket[i].name << endl;
				receipt << fixed << setprecision(2) << "Price: £" << basket[i].price / 100.00 << endl << endl;

				total += basket[i].price;
			}

			receipt << fixed << setprecision(2) << "Total: £" << total / 100;

			receipt.close();

			this->Hide();
			basket.clear();*/
		}

		private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			basket.clear();
		}
	};
};