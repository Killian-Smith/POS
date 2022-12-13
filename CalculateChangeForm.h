#pragma once
#include <iostream>
#include <string>
#include "Header.h"
#include "ReceiptForm.h"

double totalDue;
string totalGivenPounds = "";

namespace POS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CalculateChangeForm : public System::Windows::Forms::Form {
	public:

		CalculateChangeForm(void) {
			InitializeComponent();
			for (int i = 0; i < basket.size(); i++) {
				totalDue += basket[i].price / 100.00;
				}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalculateChangeForm()
		{
			if (components)
			{
				delete components;
			}
		}

		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		System::Windows::Forms::Button^ number1;
		System::Windows::Forms::Button^ number2;
		System::Windows::Forms::Button^ number3;
		System::Windows::Forms::Button^ number4;
		System::Windows::Forms::Button^ number5;
		System::Windows::Forms::Button^ number6;
		System::Windows::Forms::Button^ number7;
		System::Windows::Forms::Button^ number8;
		System::Windows::Forms::Button^ number9;
		System::Windows::Forms::Button^ clearButton;
		System::Windows::Forms::Button^ number0;
		System::Windows::Forms::Button^ button5p;
		System::Windows::Forms::Button^ button10p;
		System::Windows::Forms::Button^ button20p;
		System::Windows::Forms::Button^ backspaceButton;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		System::Windows::Forms::SplitContainer^ splitContainer1;
		System::Windows::Forms::Label^ totalDueLabel;
		System::Windows::Forms::Label^ totalGivenLabel;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
		System::Windows::Forms::Button^ changeButton;
		System::Windows::Forms::Button^ button50p;
		System::Windows::Forms::Button^ finishButton;
		System::Windows::Forms::Label^ changeDueLabel;
	protected:

		double totalGiven;

		void addToTotalGiven(string num) {
			if (totalGivenPounds.length() < 6) {
				totalGivenPounds += num;
				totalGiven = stoi(totalGivenPounds);

				ostringstream intTotal;

				intTotal << fixed << setprecision(2);

				intTotal << totalGiven / 100 << endl;

				string str = intTotal.str();

				totalGivenLabel->Text = "Total Given: £" + gcnew String(str.c_str());
			}
		}

		void clear() {
			totalGiven = 0;
			totalGivenPounds = "";

			ostringstream intTotal;

			intTotal << fixed << setprecision(2);
			intTotal << totalGiven / 100 << endl;

			string str = intTotal.str();

			totalGivenLabel->Text = "Total Given: £" + gcnew String(str.c_str());
		}

		void backspace() {
			if (totalGivenPounds.size() > 0) {
				totalGivenPounds.pop_back();

				if (totalGivenPounds.length() != 0) {
					totalGiven = stoi(totalGivenPounds);
				} else {
					totalGiven = 0;
				}

				ostringstream intTotal;

				intTotal << fixed << setprecision(2);

				intTotal << totalGiven / 100 << endl;

				string str = intTotal.str();

				totalGivenLabel->Text = "Total Given: £" + gcnew String(str.c_str());
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->changeDueLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->number1 = (gcnew System::Windows::Forms::Button());
			this->number2 = (gcnew System::Windows::Forms::Button());
			this->number3 = (gcnew System::Windows::Forms::Button());
			this->number4 = (gcnew System::Windows::Forms::Button());
			this->number5 = (gcnew System::Windows::Forms::Button());
			this->number6 = (gcnew System::Windows::Forms::Button());
			this->number7 = (gcnew System::Windows::Forms::Button());
			this->number8 = (gcnew System::Windows::Forms::Button());
			this->number9 = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->number0 = (gcnew System::Windows::Forms::Button());
			this->button5p = (gcnew System::Windows::Forms::Button());
			this->button10p = (gcnew System::Windows::Forms::Button());
			this->button20p = (gcnew System::Windows::Forms::Button());
			this->backspaceButton = (gcnew System::Windows::Forms::Button());
			this->button50p = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->totalDueLabel = (gcnew System::Windows::Forms::Label());
			this->totalGivenLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->changeButton = (gcnew System::Windows::Forms::Button());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// changeDueLabel
			// 
			this->changeDueLabel->AutoSize = true;
			this->changeDueLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->changeDueLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->changeDueLabel->Location = System::Drawing::Point(3, 576);
			this->changeDueLabel->Name = L"changeDueLabel";
			this->changeDueLabel->Size = System::Drawing::Size(238, 144);
			this->changeDueLabel->TabIndex = 4;
			this->changeDueLabel->Text = L"Change Due: £0.00";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->number1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->number2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->number3, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->number4, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->number5, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->number6, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->number7, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->number8, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->number9, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->clearButton, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->number0, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->button5p, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->button10p, 3, 1);
			this->tableLayoutPanel2->Controls->Add(this->button20p, 3, 2);
			this->tableLayoutPanel2->Controls->Add(this->backspaceButton, 2, 3);
			this->tableLayoutPanel2->Controls->Add(this->button50p, 3, 3);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(247, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(565, 570);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// number1
			// 
			this->number1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number1->Location = System::Drawing::Point(3, 3);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(135, 136);
			this->number1->TabIndex = 0;
			this->number1->Text = L"1";
			this->number1->UseVisualStyleBackColor = true;
			this->number1->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number1_Click);
			// 
			// number2
			// 
			this->number2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number2->Location = System::Drawing::Point(144, 3);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(135, 136);
			this->number2->TabIndex = 1;
			this->number2->Text = L"2";
			this->number2->UseVisualStyleBackColor = true;
			this->number2->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number2_Click);
			// 
			// number3
			// 
			this->number3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number3->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number3->Location = System::Drawing::Point(285, 3);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(135, 136);
			this->number3->TabIndex = 2;
			this->number3->Text = L"3";
			this->number3->UseVisualStyleBackColor = true;
			this->number3->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number3_Click);
			// 
			// number4
			// 
			this->number4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number4->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number4->Location = System::Drawing::Point(3, 145);
			this->number4->Name = L"number4";
			this->number4->Size = System::Drawing::Size(135, 136);
			this->number4->TabIndex = 3;
			this->number4->Text = L"4";
			this->number4->UseVisualStyleBackColor = true;
			this->number4->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number4_Click);
			// 
			// number5
			// 
			this->number5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number5->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number5->Location = System::Drawing::Point(144, 145);
			this->number5->Name = L"number5";
			this->number5->Size = System::Drawing::Size(135, 136);
			this->number5->TabIndex = 4;
			this->number5->Text = L"5";
			this->number5->UseVisualStyleBackColor = true;
			this->number5->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number5_Click);
			// 
			// number6
			// 
			this->number6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number6->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number6->Location = System::Drawing::Point(285, 145);
			this->number6->Name = L"number6";
			this->number6->Size = System::Drawing::Size(135, 136);
			this->number6->TabIndex = 5;
			this->number6->Text = L"6";
			this->number6->UseVisualStyleBackColor = true;
			this->number6->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number6_Click);
			// 
			// number7
			// 
			this->number7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number7->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number7->Location = System::Drawing::Point(3, 287);
			this->number7->Name = L"number7";
			this->number7->Size = System::Drawing::Size(135, 136);
			this->number7->TabIndex = 6;
			this->number7->Text = L"7";
			this->number7->UseVisualStyleBackColor = true;
			this->number7->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number7_Click);
			// 
			// number8
			// 
			this->number8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number8->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number8->Location = System::Drawing::Point(144, 287);
			this->number8->Name = L"number8";
			this->number8->Size = System::Drawing::Size(135, 136);
			this->number8->TabIndex = 7;
			this->number8->Text = L"8";
			this->number8->UseVisualStyleBackColor = true;
			this->number8->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number8_Click);
			// 
			// number9
			// 
			this->number9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number9->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number9->Location = System::Drawing::Point(285, 287);
			this->number9->Name = L"number9";
			this->number9->Size = System::Drawing::Size(135, 136);
			this->number9->TabIndex = 8;
			this->number9->Text = L"9";
			this->number9->UseVisualStyleBackColor = true;
			this->number9->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number9_Click);
			// 
			// clearButton
			// 
			this->clearButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearButton->Location = System::Drawing::Point(3, 429);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(135, 138);
			this->clearButton->TabIndex = 9;
			this->clearButton->Text = L"C";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &CalculateChangeForm::clearButton_Click);
			// 
			// number0
			// 
			this->number0->Dock = System::Windows::Forms::DockStyle::Fill;
			this->number0->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number0->Location = System::Drawing::Point(144, 429);
			this->number0->Name = L"number0";
			this->number0->Size = System::Drawing::Size(135, 138);
			this->number0->TabIndex = 10;
			this->number0->Text = L"0";
			this->number0->UseVisualStyleBackColor = true;
			this->number0->Click += gcnew System::EventHandler(this, &CalculateChangeForm::Number0_Click);
			// 
			// button5p
			// 
			this->button5p->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5p->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5p->Location = System::Drawing::Point(426, 3);
			this->button5p->Name = L"button5p";
			this->button5p->Size = System::Drawing::Size(136, 136);
			this->button5p->TabIndex = 12;
			this->button5p->Text = L"£5";
			this->button5p->UseVisualStyleBackColor = true;
			this->button5p->Click += gcnew System::EventHandler(this, &CalculateChangeForm::button5p_Click);
			// 
			// button10p
			// 
			this->button10p->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button10p->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10p->Location = System::Drawing::Point(426, 145);
			this->button10p->Name = L"button10p";
			this->button10p->Size = System::Drawing::Size(136, 136);
			this->button10p->TabIndex = 13;
			this->button10p->Text = L"£10";
			this->button10p->UseVisualStyleBackColor = true;
			this->button10p->Click += gcnew System::EventHandler(this, &CalculateChangeForm::button10p_Click);
			// 
			// button20p
			// 
			this->button20p->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button20p->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20p->Location = System::Drawing::Point(426, 287);
			this->button20p->Name = L"button20p";
			this->button20p->Size = System::Drawing::Size(136, 136);
			this->button20p->TabIndex = 14;
			this->button20p->Text = L"£20";
			this->button20p->UseVisualStyleBackColor = true;
			this->button20p->Click += gcnew System::EventHandler(this, &CalculateChangeForm::button20p_Click);
			// 
			// backspaceButton
			// 
			this->backspaceButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->backspaceButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->backspaceButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backspaceButton->Location = System::Drawing::Point(285, 429);
			this->backspaceButton->Name = L"backspaceButton";
			this->backspaceButton->Size = System::Drawing::Size(135, 138);
			this->backspaceButton->TabIndex = 15;
			this->backspaceButton->Text = L"Backspace";
			this->backspaceButton->UseVisualStyleBackColor = false;
			this->backspaceButton->Click += gcnew System::EventHandler(this, &CalculateChangeForm::BackspaceButton_Click);
			// 
			// button50p
			// 
			this->button50p->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button50p->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button50p->Location = System::Drawing::Point(426, 429);
			this->button50p->Name = L"button50p";
			this->button50p->Size = System::Drawing::Size(136, 138);
			this->button50p->TabIndex = 16;
			this->button50p->Text = L"£50";
			this->button50p->UseVisualStyleBackColor = true;
			this->button50p->Click += gcnew System::EventHandler(this, &CalculateChangeForm::button50p_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->splitContainer1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->changeDueLabel, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(815, 720);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->totalDueLabel);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->totalGivenLabel);
			this->splitContainer1->Size = System::Drawing::Size(238, 570);
			this->splitContainer1->SplitterDistance = 45;
			this->splitContainer1->TabIndex = 2;
			// 
			// totalDueLabel
			// 
			this->totalDueLabel->AutoSize = true;
			this->totalDueLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->totalDueLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalDueLabel->Location = System::Drawing::Point(0, 0);
			this->totalDueLabel->Name = L"totalDueLabel";
			this->totalDueLabel->Padding = System::Windows::Forms::Padding(0, 6, 0, 0);
			this->totalDueLabel->Size = System::Drawing::Size(95, 28);
			this->totalDueLabel->TabIndex = 0;
			this->totalDueLabel->Text = L"Total Due:";
			// 
			// totalGivenLabel
			// 
			this->totalGivenLabel->AutoSize = true;
			this->totalGivenLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->totalGivenLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalGivenLabel->Location = System::Drawing::Point(0, 0);
			this->totalGivenLabel->Name = L"totalGivenLabel";
			this->totalGivenLabel->Size = System::Drawing::Size(163, 22);
			this->totalGivenLabel->TabIndex = 0;
			this->totalGivenLabel->Text = L"Total Given: £0.00";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->changeButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->finishButton, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(247, 579);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(565, 138);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// changeButton
			// 
			this->changeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(104)));
			this->changeButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->changeButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->changeButton->Location = System::Drawing::Point(3, 3);
			this->changeButton->Name = L"changeButton";
			this->changeButton->Size = System::Drawing::Size(276, 132);
			this->changeButton->TabIndex = 0;
			this->changeButton->Text = L"Calculate Change";
			this->changeButton->UseVisualStyleBackColor = false;
			this->changeButton->Click += gcnew System::EventHandler(this, &CalculateChangeForm::changeButton_Click);
			// 
			// finishButton
			// 
			this->finishButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(104)));
			this->finishButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finishButton->Location = System::Drawing::Point(285, 3);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(277, 132);
			this->finishButton->TabIndex = 1;
			this->finishButton->Text = L"Finish";
			this->finishButton->UseVisualStyleBackColor = false;
			this->finishButton->Click += gcnew System::EventHandler(this, &CalculateChangeForm::FinishButton_Click);
			// 
			// CalculateChangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(815, 720);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CalculateChangeForm";
			this->Text = L"CalculateChange";
			this->Load += gcnew System::EventHandler(this, &CalculateChangeForm::CalculateChangeForm_Load);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void CalculateChangeForm_Load(System::Object^ sender, System::EventArgs^ e) {
			totalDueLabel->Text = "Total Due: £" + Math::Round(totalDue, 2).ToString("F2");
		}
		private: System::Void Number1_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("1");
		}
		private: System::Void Number2_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("2");
		}
		private: System::Void Number3_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("3");
		}
		private: System::Void Number4_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("4");
		}
		private: System::Void Number5_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("5");
		}
		private: System::Void Number6_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("6");
		}
		private: System::Void Number7_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("7");
		}
		private: System::Void Number8_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("8");
		}
		private: System::Void Number9_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("9");
		}
		private: System::Void Number0_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven("0");
		}
		private: System::Void PeriodButton_Click(System::Object^ sender, System::EventArgs^ e) {
			addToTotalGiven(".");
		}
		private: System::Void button5p_Click(System::Object^ sender, System::EventArgs^ e) {
			totalGivenPounds = "";
			addToTotalGiven("500");
		}
		private: System::Void button10p_Click(System::Object^ sender, System::EventArgs^ e) {
			totalGivenPounds = "";
			addToTotalGiven("1000");
		}
		private: System::Void button20p_Click(System::Object^ sender, System::EventArgs^ e) {
			totalGivenPounds = "";
			addToTotalGiven("2000");
		}
		private: System::Void button50p_Click(System::Object^ sender, System::EventArgs^ e) {
			totalGivenPounds = "";
			addToTotalGiven("5000");
		}
		private: System::Void BackspaceButton_Click(System::Object^ sender, System::EventArgs^ e) {
			backspace();
		}
		private: System::Void changeButton_Click(System::Object^ sender, System::EventArgs^ e) {
			cout << totalGiven << endl << totalDue << endl;

			double due = (totalGiven - (totalDue * 100)) / 100;

			changeDueLabel->Text = "Change Due: £" + Math::Round(due, 2).ToString("F2");
		}
		private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
			clear();
		}
		private: System::Void FinishButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			ReceiptForm^ receiptForm;
			receiptForm = (gcnew ReceiptForm());
			receiptForm->Show();
		}
};
}
