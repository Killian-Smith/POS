#pragma once

#include <iostream>
#include "Header.h"

using namespace std;

namespace POS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		void InitializeComponent(void)
		{
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
			this->printButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->printButton->Location = System::Drawing::Point(0, 0);
			this->printButton->Name = L"printButton";
			this->printButton->Size = System::Drawing::Size(289, 175);
			this->printButton->TabIndex = 0;
			this->printButton->Text = L"Print";
			this->printButton->UseVisualStyleBackColor = true;
			this->printButton->Click += gcnew System::EventHandler(this, &ReceiptForm::PrintButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cancelButton->Location = System::Drawing::Point(0, 0);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(285, 175);
			this->cancelButton->TabIndex = 0;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &ReceiptForm::CancelButton_Click);
			// 
			// printLabel
			// 
			this->printLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->printLabel->AutoSize = true;
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
#pragma endregion

	private: System::Void PrintButton_Click(System::Object^ sender, System::EventArgs^ e) {
	    fstream receipt;
		receipt.open("receipt.txt");
		receipt.clear();

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
	}
	private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	};

	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void)
		{
			InitializeComponent();		
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
		System::Windows::Forms::Button^ button13;
		System::Windows::Forms::Button^ button14;

		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;
		System::Windows::Forms::Button^ button10;
		System::Windows::Forms::Button^ button11;
		System::Windows::Forms::Button^ button12;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		System::Windows::Forms::FlowLayoutPanel^ items;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
		System::Windows::Forms::Button^ chargeButton;
		System::ComponentModel::IContainer^ components;

		void getItems() {
			this->items->Controls->Clear();
			this->chargeButton->Text = "Charge";


			double total = 0;
			for (int i = 0; i < basket.size(); i++) {
				System::Windows::Forms::Button^ item;
				item = (gcnew System::Windows::Forms::Button());

				item->Location = System::Drawing::Point(3, 3);
				item->Name = "item" + i;
				item->Size = System::Drawing::Size(items->Width - 25, 100);
				item->TabIndex = 0;
				item->Text = gcnew String(basket[i].name.c_str());
				item->UseVisualStyleBackColor = true;

				this->Controls->Add(item);
				this->items->Controls->Add(item);

				total += basket[i].price / 100.00;

				this->chargeButton->Text = "Charge £" + total.ToString();
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->items = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chargeButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->button13, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->button14, 1, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(383, 731);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1136, 307);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// button13
			// 
			this->button13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button13->Location = System::Drawing::Point(3, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(562, 147);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Remove Last Item";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::Button13_Click);
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button14->Location = System::Drawing::Point(571, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(562, 147);
			this->button14->TabIndex = 1;
			this->button14->Text = L"Restart";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::Button14_Click);
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
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->button3, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->button4, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->button5, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button7, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->button8, 3, 1);
			this->tableLayoutPanel2->Controls->Add(this->button9, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->button10, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->button11, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->button12, 3, 2);
			this->tableLayoutPanel2->Controls->Add(this->button6, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(383, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1136, 722);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(278, 234);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Sausage Roll\r\n£0.80";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(287, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(278, 234);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Fry\r\n£2.50\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(571, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(278, 234);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Curry and Rice\r\n£1.80";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(855, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(278, 234);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Chips\r\n£1.50";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::Button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(3, 243);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(278, 234);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Baked Potato\r\n£1.45";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::Button5_Click);
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button7->Location = System::Drawing::Point(571, 243);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(278, 234);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Pizza Topping\r\n£0.25";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::Button7_Click);
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button8->Location = System::Drawing::Point(855, 243);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(278, 234);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Panini\r\n£2.40";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::Button8_Click);
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button9->Location = System::Drawing::Point(3, 483);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(278, 236);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Soup\r\n£1.00";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::Button9_Click);
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button10->Location = System::Drawing::Point(287, 483);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(278, 236);
			this->button10->TabIndex = 9;
			this->button10->Text = L"Bottles\r\n£1.20";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::Button10_Click);
			// 
			// button11
			// 
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button11->Location = System::Drawing::Point(571, 483);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(278, 236);
			this->button11->TabIndex = 10;
			this->button11->Text = L"Soda\r\n£1.60";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::Button11_Click);
			// 
			// button12
			// 
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button12->Location = System::Drawing::Point(855, 483);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(278, 236);
			this->button12->TabIndex = 11;
			this->button12->Text = L"Tea or Coffe\r\n£0.90";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::Button12_Click);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button6->Location = System::Drawing::Point(287, 243);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(278, 234);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Pizza\r\n£2.50";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::Button6_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->items, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 2, 1);
			this->tableLayoutPanel1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1904, 1041);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// items
			// 
			this->items->AutoScroll = true;
			this->items->Dock = System::Windows::Forms::DockStyle::Fill;
			this->items->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->items->Location = System::Drawing::Point(1525, 3);
			this->items->Name = L"items";
			this->items->Size = System::Drawing::Size(376, 722);
			this->items->TabIndex = 4;
			this->items->WrapContents = false;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel4->Controls->Add(this->chargeButton, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(1525, 731);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(376, 307);
			this->tableLayoutPanel4->TabIndex = 5;
			// 
			// chargeButton
			// 
			this->chargeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chargeButton->Location = System::Drawing::Point(3, 3);
			this->chargeButton->Name = L"chargeButton";
			this->chargeButton->Size = System::Drawing::Size(370, 147);
			this->chargeButton->TabIndex = 1;
			this->chargeButton->Text = L"Charge";
			this->chargeButton->UseVisualStyleBackColor = true;
			this->chargeButton->Click += gcnew System::EventHandler(this, &MyForm::ChargeButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Name = L"MyForm";
			this->Text = L"POS";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(SausageRoll);
			getItems();
		}
		private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Fry);
			getItems();
		}
		private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(CurryRice);
			getItems();
		}
		private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Chips);
			getItems();
		}
		private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(BakedPotato);
			getItems();
		}
		private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Pizza);
			getItems();
		}
		private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(PizzaTopping);
			getItems();
		}
		private: System::Void Button8_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Panini);
			getItems();
		}
		private: System::Void Button9_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Soup);
			getItems();
		}
		private: System::Void Button10_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Bottle);
			getItems();
		}
		private: System::Void Button11_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(Soda);
			getItems();
		}
		private: System::Void Button12_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.push_back(TeaCoffee);
			getItems();
		}

		private: System::Void Button13_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.pop_back();
			getItems();
		}
		private: System::Void Button14_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.clear();
			getItems();
		}
		private: System::Void ChargeButton_Click(System::Object^ sender, System::EventArgs^ e) {
			ReceiptForm^ receiptForm;
			receiptForm = (gcnew ReceiptForm());

			receiptForm->Show();
		}
	};	
}