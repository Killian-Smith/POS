#pragma once

#include <iostream>
#include <cmath>
#include "Header.h"
#include "ReceiptForm.h"
#include "CalculateChangeForm.h"

using namespace std;

namespace POS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
				auto buttonText = gcnew String(basket[i].name.c_str());

				System::Windows::Forms::Button^ item;
				item = (gcnew System::Windows::Forms::Button());

				item->Location = System::Drawing::Point(3, 3);
				item->Name = "item" + i;
				item->Size = System::Drawing::Size(items->Width - 25, 100);
				item->TabIndex = 0;
				item->Text = buttonText + "\r\n£" + Math::Round(basket[i].price / 100.00, 2).ToString("F2");
				item->UseVisualStyleBackColor = true;

				this->Controls->Add(item);
				this->items->Controls->Add(item);

				total += basket[i].price / 100.00;

				this->chargeButton->Text = "Charge £" + Math::Round(total, 2).ToString("F2");
			}
		}

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
			this->tableLayoutPanel3->Location = System::Drawing::Point(291, 619);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(860, 259);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// button13
			// 
			this->button13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(3, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(424, 123);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Remove Last Item";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::Button13_Click);
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(433, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(424, 123);
			this->button14->TabIndex = 1;
			this->button14->Text = L"Restart";
			this->button14->UseVisualStyleBackColor = false;
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
			this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(291, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(860, 610);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 197);
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
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(218, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(209, 197);
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
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(433, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(209, 197);
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
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(648, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(209, 197);
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
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(3, 206);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(209, 197);
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
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(433, 206);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(209, 197);
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
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(648, 206);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(209, 197);
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
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(3, 409);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(209, 198);
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
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(218, 409);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(209, 198);
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
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(433, 409);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(209, 198);
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
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(648, 409);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(209, 198);
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
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(218, 206);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(209, 197);
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(1444, 881);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// items
			// 
			this->items->AutoScroll = true;
			this->items->Dock = System::Windows::Forms::DockStyle::Fill;
			this->items->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->items->Location = System::Drawing::Point(1157, 3);
			this->items->Name = L"items";
			this->items->Size = System::Drawing::Size(284, 610);
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
			this->tableLayoutPanel4->Location = System::Drawing::Point(1157, 619);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(284, 259);
			this->tableLayoutPanel4->TabIndex = 5;
			// 
			// chargeButton
			// 
			this->chargeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chargeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(104)));
			this->chargeButton->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chargeButton->Location = System::Drawing::Point(3, 3);
			this->chargeButton->Name = L"chargeButton";
			this->chargeButton->Size = System::Drawing::Size(278, 123);
			this->chargeButton->TabIndex = 1;
			this->chargeButton->Text = L"Charge";
			this->chargeButton->UseVisualStyleBackColor = false;
			this->chargeButton->Click += gcnew System::EventHandler(this, &MyForm::ChargeButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1444, 881);
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
			if (basket.size() != 0) {
				basket.pop_back();
				getItems();
			}
			
		}
		private: System::Void Button14_Click(System::Object^ sender, System::EventArgs^ e) {
			basket.clear();
			getItems();
		}
		private: System::Void ChargeButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (basket.size() != 0) {
				
				auto result = MessageBox::Show("Is the customer paying with cash?", "Payment", MessageBoxButtons::YesNo);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					CalculateChangeForm^ calculateChangeForm;
					calculateChangeForm = (gcnew CalculateChangeForm());
					calculateChangeForm->Show();
				} else {
					ReceiptForm^ receiptForm;
					receiptForm = (gcnew ReceiptForm());
					receiptForm->Show();
				}
			}
			else {
				MessageBox::Show("Basket must have at least one item.", "Error");
			}
			
		}
	};	
}