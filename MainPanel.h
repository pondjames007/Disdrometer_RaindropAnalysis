#pragma once

#include "Drop.h"
#include <fstream>
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

#include <pylon/gige/BaslerGigEInstantCamera.h>
typedef Pylon::CBaslerGigEInstantCamera Camera_t;
using namespace Basler_GigECameraParams;

Mat frame1, frame2;
Mat grayImg1, grayImg2;
Mat partImg1, partImg2;
Mat backGround;
Mat diffImg, threshImg, finalImg;
vector<Drop> dropsOfFrame1;
vector<Drop> dropsOfFrame2;

bool finDel = false;


namespace GUItry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;
	using namespace Pylon;


	/// <summary>
	/// MainPanel 的摘要
	/// </summary>
	public ref class MainPanel : public System::Windows::Forms::Form
	{
	public:
		MainPanel(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainPanel()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  StartCamera;
	private: System::Windows::Forms::Label^  ImageName;
	private: System::Windows::Forms::Button^  Exit;
	private: System::Windows::Forms::PictureBox^  imageTaken;
	private: System::Windows::Forms::PictureBox^  imageProcessed;
	private: System::Windows::Forms::Button^  opticalFlow;
	private: System::Windows::Forms::Button^  piv;
	private: System::Windows::Forms::Button^  cameraTake;
	private: System::Windows::Forms::Panel^  Data;
	private: System::Windows::Forms::Label^  LabelArea;

	private: System::Windows::Forms::Label^  numDrops;
	private: System::Windows::Forms::Label^  LabelDrops;
	private: System::Windows::Forms::Label^  SpeDrop;
	private: System::Windows::Forms::ComboBox^  dropChoose;
	private: System::Windows::Forms::Label^  avgNumVel;
	private: System::Windows::Forms::Label^  avgLblVel;
	private: System::Windows::Forms::Label^  avgNumArea;
	private: System::Windows::Forms::Label^  avgLblArea;
	private: System::Windows::Forms::Label^  numVel;
	private: System::Windows::Forms::Label^  LabelVel;
	private: System::Windows::Forms::Label^  numArea;
	private: System::Windows::Forms::Label^  numDist;
	private: System::Windows::Forms::Label^  LabelDist;
	private: System::Windows::Forms::Label^  DataZone;
	private: System::Windows::Forms::Panel^  CamPara;

	private: System::Windows::Forms::TextBox^  numGain;
	private: System::Windows::Forms::TextBox^  numExpo;
	private: System::Windows::Forms::TextBox^  numPhoto;

	private: System::Windows::Forms::Label^  CameraZone;
	private: System::Windows::Forms::Label^  Gain;
	private: System::Windows::Forms::Label^  ExpoTime;
	private: System::Windows::Forms::Label^  numFps;
	private: System::Windows::Forms::Label^  fps;
	private: System::Windows::Forms::Label^  LabelPhoto;
	private: System::Windows::Forms::TrackBar^  trackPhoto;

	private: System::Windows::Forms::Label^  message;
	private: System::Windows::Forms::Label^  numFrame;

	private: System::Windows::Forms::Label^  lblNumFrame;

	private: System::Windows::Forms::ComboBox^  frameChoose;
	private: System::Windows::Forms::Label^  LabelFrame;


	private: System::Windows::Forms::TrackBar^  trackGain;
	private: System::Windows::Forms::TrackBar^  trackExpo;





	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartCamera = (gcnew System::Windows::Forms::Button());
			this->ImageName = (gcnew System::Windows::Forms::Label());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->imageTaken = (gcnew System::Windows::Forms::PictureBox());
			this->imageProcessed = (gcnew System::Windows::Forms::PictureBox());
			this->opticalFlow = (gcnew System::Windows::Forms::Button());
			this->piv = (gcnew System::Windows::Forms::Button());
			this->cameraTake = (gcnew System::Windows::Forms::Button());
			this->Data = (gcnew System::Windows::Forms::Panel());
			this->numFrame = (gcnew System::Windows::Forms::Label());
			this->lblNumFrame = (gcnew System::Windows::Forms::Label());
			this->frameChoose = (gcnew System::Windows::Forms::ComboBox());
			this->LabelFrame = (gcnew System::Windows::Forms::Label());
			this->DataZone = (gcnew System::Windows::Forms::Label());
			this->numDist = (gcnew System::Windows::Forms::Label());
			this->LabelDist = (gcnew System::Windows::Forms::Label());
			this->SpeDrop = (gcnew System::Windows::Forms::Label());
			this->dropChoose = (gcnew System::Windows::Forms::ComboBox());
			this->avgNumVel = (gcnew System::Windows::Forms::Label());
			this->avgLblVel = (gcnew System::Windows::Forms::Label());
			this->avgNumArea = (gcnew System::Windows::Forms::Label());
			this->avgLblArea = (gcnew System::Windows::Forms::Label());
			this->numVel = (gcnew System::Windows::Forms::Label());
			this->LabelVel = (gcnew System::Windows::Forms::Label());
			this->numArea = (gcnew System::Windows::Forms::Label());
			this->LabelArea = (gcnew System::Windows::Forms::Label());
			this->numDrops = (gcnew System::Windows::Forms::Label());
			this->LabelDrops = (gcnew System::Windows::Forms::Label());
			this->CamPara = (gcnew System::Windows::Forms::Panel());
			this->trackExpo = (gcnew System::Windows::Forms::TrackBar());
			this->trackGain = (gcnew System::Windows::Forms::TrackBar());
			this->trackPhoto = (gcnew System::Windows::Forms::TrackBar());
			this->numGain = (gcnew System::Windows::Forms::TextBox());
			this->numExpo = (gcnew System::Windows::Forms::TextBox());
			this->numPhoto = (gcnew System::Windows::Forms::TextBox());
			this->CameraZone = (gcnew System::Windows::Forms::Label());
			this->Gain = (gcnew System::Windows::Forms::Label());
			this->ExpoTime = (gcnew System::Windows::Forms::Label());
			this->numFps = (gcnew System::Windows::Forms::Label());
			this->fps = (gcnew System::Windows::Forms::Label());
			this->LabelPhoto = (gcnew System::Windows::Forms::Label());
			this->message = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imageTaken))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imageProcessed))->BeginInit();
			this->Data->SuspendLayout();
			this->CamPara->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackExpo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackGain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// StartCamera
			// 
			this->StartCamera->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->StartCamera->Location = System::Drawing::Point(12, 571);
			this->StartCamera->Name = L"StartCamera";
			this->StartCamera->Size = System::Drawing::Size(95, 30);
			this->StartCamera->TabIndex = 1;
			this->StartCamera->Text = L"START";
			this->StartCamera->UseVisualStyleBackColor = true;
			this->StartCamera->Click += gcnew System::EventHandler(this, &MainPanel::StartCamera_Click);
			// 
			// ImageName
			// 
			this->ImageName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ImageName->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ImageName->Location = System::Drawing::Point(12, 535);
			this->ImageName->Name = L"ImageName";
			this->ImageName->Size = System::Drawing::Size(581, 20);
			this->ImageName->TabIndex = 2;
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Exit->Location = System::Drawing::Point(129, 571);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(95, 30);
			this->Exit->TabIndex = 3;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &MainPanel::Exit_Click);
			// 
			// imageTaken
			// 
			this->imageTaken->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imageTaken->Location = System::Drawing::Point(12, 32);
			this->imageTaken->Name = L"imageTaken";
			this->imageTaken->Size = System::Drawing::Size(659, 494);
			this->imageTaken->TabIndex = 4;
			this->imageTaken->TabStop = false;
			// 
			// imageProcessed
			// 
			this->imageProcessed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imageProcessed->Location = System::Drawing::Point(713, 32);
			this->imageProcessed->Name = L"imageProcessed";
			this->imageProcessed->Size = System::Drawing::Size(659, 494);
			this->imageProcessed->TabIndex = 5;
			this->imageProcessed->TabStop = false;
			// 
			// opticalFlow
			// 
			this->opticalFlow->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->opticalFlow->Location = System::Drawing::Point(253, 571);
			this->opticalFlow->Name = L"opticalFlow";
			this->opticalFlow->Size = System::Drawing::Size(95, 30);
			this->opticalFlow->TabIndex = 6;
			this->opticalFlow->Text = L"OpticalFlow";
			this->opticalFlow->UseVisualStyleBackColor = true;
			this->opticalFlow->Click += gcnew System::EventHandler(this, &MainPanel::opticalFlow_Click);
			// 
			// piv
			// 
			this->piv->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->piv->Location = System::Drawing::Point(376, 571);
			this->piv->Name = L"piv";
			this->piv->Size = System::Drawing::Size(95, 30);
			this->piv->TabIndex = 7;
			this->piv->Text = L"PIV";
			this->piv->UseVisualStyleBackColor = true;
			this->piv->Click += gcnew System::EventHandler(this, &MainPanel::piv_Click);
			// 
			// cameraTake
			// 
			this->cameraTake->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cameraTake->Location = System::Drawing::Point(498, 571);
			this->cameraTake->Name = L"cameraTake";
			this->cameraTake->Size = System::Drawing::Size(95, 30);
			this->cameraTake->TabIndex = 8;
			this->cameraTake->Text = L"Camera";
			this->cameraTake->UseVisualStyleBackColor = true;
			this->cameraTake->Click += gcnew System::EventHandler(this, &MainPanel::cameraTake_Click);
			// 
			// Data
			// 
			this->Data->Controls->Add(this->numFrame);
			this->Data->Controls->Add(this->lblNumFrame);
			this->Data->Controls->Add(this->frameChoose);
			this->Data->Controls->Add(this->LabelFrame);
			this->Data->Controls->Add(this->DataZone);
			this->Data->Controls->Add(this->numDist);
			this->Data->Controls->Add(this->LabelDist);
			this->Data->Controls->Add(this->SpeDrop);
			this->Data->Controls->Add(this->dropChoose);
			this->Data->Controls->Add(this->avgNumVel);
			this->Data->Controls->Add(this->avgLblVel);
			this->Data->Controls->Add(this->avgNumArea);
			this->Data->Controls->Add(this->avgLblArea);
			this->Data->Controls->Add(this->numVel);
			this->Data->Controls->Add(this->LabelVel);
			this->Data->Controls->Add(this->numArea);
			this->Data->Controls->Add(this->LabelArea);
			this->Data->Controls->Add(this->numDrops);
			this->Data->Controls->Add(this->LabelDrops);
			this->Data->Location = System::Drawing::Point(713, 558);
			this->Data->Name = L"Data";
			this->Data->Size = System::Drawing::Size(659, 409);
			this->Data->TabIndex = 9;
			// 
			// numFrame
			// 
			this->numFrame->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numFrame->Location = System::Drawing::Point(159, 70);
			this->numFrame->Name = L"numFrame";
			this->numFrame->Size = System::Drawing::Size(115, 20);
			this->numFrame->TabIndex = 18;
			this->numFrame->Text = L"0";
			// 
			// lblNumFrame
			// 
			this->lblNumFrame->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblNumFrame->Location = System::Drawing::Point(16, 70);
			this->lblNumFrame->Name = L"lblNumFrame";
			this->lblNumFrame->Size = System::Drawing::Size(115, 20);
			this->lblNumFrame->TabIndex = 17;
			this->lblNumFrame->Text = L"#Frames";
			this->lblNumFrame->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// frameChoose
			// 
			this->frameChoose->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->frameChoose->FormattingEnabled = true;
			this->frameChoose->Location = System::Drawing::Point(163, 112);
			this->frameChoose->Name = L"frameChoose";
			this->frameChoose->Size = System::Drawing::Size(45, 27);
			this->frameChoose->TabIndex = 16;
			this->frameChoose->SelectedIndexChanged += gcnew System::EventHandler(this, &MainPanel::frameChoose_SelectedIndexChanged);
			// 
			// LabelFrame
			// 
			this->LabelFrame->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelFrame->Location = System::Drawing::Point(16, 112);
			this->LabelFrame->Name = L"LabelFrame";
			this->LabelFrame->Size = System::Drawing::Size(115, 20);
			this->LabelFrame->TabIndex = 15;
			this->LabelFrame->Text = L"Frame";
			this->LabelFrame->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DataZone
			// 
			this->DataZone->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DataZone->Location = System::Drawing::Point(3, 3);
			this->DataZone->Name = L"DataZone";
			this->DataZone->Size = System::Drawing::Size(115, 30);
			this->DataZone->TabIndex = 14;
			this->DataZone->Text = L"Data Zone";
			this->DataZone->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numDist
			// 
			this->numDist->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numDist->Location = System::Drawing::Point(159, 290);
			this->numDist->Name = L"numDist";
			this->numDist->Size = System::Drawing::Size(115, 20);
			this->numDist->TabIndex = 13;
			this->numDist->Text = L"0";
			// 
			// LabelDist
			// 
			this->LabelDist->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelDist->Location = System::Drawing::Point(16, 289);
			this->LabelDist->Name = L"LabelDist";
			this->LabelDist->Size = System::Drawing::Size(115, 20);
			this->LabelDist->TabIndex = 12;
			this->LabelDist->Text = L"Distance";
			this->LabelDist->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SpeDrop
			// 
			this->SpeDrop->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SpeDrop->Location = System::Drawing::Point(16, 198);
			this->SpeDrop->Name = L"SpeDrop";
			this->SpeDrop->Size = System::Drawing::Size(115, 20);
			this->SpeDrop->TabIndex = 11;
			this->SpeDrop->Text = L"Drop#";
			this->SpeDrop->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dropChoose
			// 
			this->dropChoose->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dropChoose->FormattingEnabled = true;
			this->dropChoose->Location = System::Drawing::Point(163, 198);
			this->dropChoose->Name = L"dropChoose";
			this->dropChoose->Size = System::Drawing::Size(45, 27);
			this->dropChoose->TabIndex = 10;
			this->dropChoose->SelectedIndexChanged += gcnew System::EventHandler(this, &MainPanel::dropChoose_SelectedIndexChanged);
			// 
			// avgNumVel
			// 
			this->avgNumVel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->avgNumVel->Location = System::Drawing::Point(502, 292);
			this->avgNumVel->Name = L"avgNumVel";
			this->avgNumVel->Size = System::Drawing::Size(115, 20);
			this->avgNumVel->TabIndex = 9;
			this->avgNumVel->Text = L"0";
			// 
			// avgLblVel
			// 
			this->avgLblVel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->avgLblVel->Location = System::Drawing::Point(328, 291);
			this->avgLblVel->Name = L"avgLblVel";
			this->avgLblVel->Size = System::Drawing::Size(146, 20);
			this->avgLblVel->TabIndex = 8;
			this->avgLblVel->Text = L"Average Velocity";
			this->avgLblVel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// avgNumArea
			// 
			this->avgNumArea->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->avgNumArea->Location = System::Drawing::Point(502, 245);
			this->avgNumArea->Name = L"avgNumArea";
			this->avgNumArea->Size = System::Drawing::Size(115, 20);
			this->avgNumArea->TabIndex = 7;
			this->avgNumArea->Text = L"0";
			// 
			// avgLblArea
			// 
			this->avgLblArea->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->avgLblArea->Location = System::Drawing::Point(328, 244);
			this->avgLblArea->Name = L"avgLblArea";
			this->avgLblArea->Size = System::Drawing::Size(146, 20);
			this->avgLblArea->TabIndex = 6;
			this->avgLblArea->Text = L"Average Area";
			this->avgLblArea->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numVel
			// 
			this->numVel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numVel->Location = System::Drawing::Point(159, 333);
			this->numVel->Name = L"numVel";
			this->numVel->Size = System::Drawing::Size(115, 20);
			this->numVel->TabIndex = 5;
			this->numVel->Text = L"0";
			// 
			// LabelVel
			// 
			this->LabelVel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelVel->Location = System::Drawing::Point(16, 332);
			this->LabelVel->Name = L"LabelVel";
			this->LabelVel->Size = System::Drawing::Size(115, 20);
			this->LabelVel->TabIndex = 4;
			this->LabelVel->Text = L"Velocity";
			this->LabelVel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numArea
			// 
			this->numArea->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numArea->Location = System::Drawing::Point(159, 245);
			this->numArea->Name = L"numArea";
			this->numArea->Size = System::Drawing::Size(115, 20);
			this->numArea->TabIndex = 3;
			this->numArea->Text = L"0";
			// 
			// LabelArea
			// 
			this->LabelArea->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelArea->Location = System::Drawing::Point(16, 244);
			this->LabelArea->Name = L"LabelArea";
			this->LabelArea->Size = System::Drawing::Size(115, 20);
			this->LabelArea->TabIndex = 2;
			this->LabelArea->Text = L"Area";
			this->LabelArea->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numDrops
			// 
			this->numDrops->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numDrops->Location = System::Drawing::Point(159, 156);
			this->numDrops->Name = L"numDrops";
			this->numDrops->Size = System::Drawing::Size(115, 20);
			this->numDrops->TabIndex = 1;
			this->numDrops->Text = L"0";
			// 
			// LabelDrops
			// 
			this->LabelDrops->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelDrops->Location = System::Drawing::Point(16, 156);
			this->LabelDrops->Name = L"LabelDrops";
			this->LabelDrops->Size = System::Drawing::Size(115, 20);
			this->LabelDrops->TabIndex = 0;
			this->LabelDrops->Text = L"#DropsDetected";
			this->LabelDrops->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CamPara
			// 
			this->CamPara->Controls->Add(this->trackExpo);
			this->CamPara->Controls->Add(this->trackGain);
			this->CamPara->Controls->Add(this->trackPhoto);
			this->CamPara->Controls->Add(this->numGain);
			this->CamPara->Controls->Add(this->numExpo);
			this->CamPara->Controls->Add(this->numPhoto);
			this->CamPara->Controls->Add(this->CameraZone);
			this->CamPara->Controls->Add(this->Gain);
			this->CamPara->Controls->Add(this->ExpoTime);
			this->CamPara->Controls->Add(this->numFps);
			this->CamPara->Controls->Add(this->fps);
			this->CamPara->Controls->Add(this->LabelPhoto);
			this->CamPara->Location = System::Drawing::Point(12, 623);
			this->CamPara->Name = L"CamPara";
			this->CamPara->Size = System::Drawing::Size(659, 344);
			this->CamPara->TabIndex = 10;
			// 
			// trackExpo
			// 
			this->trackExpo->LargeChange = 1000;
			this->trackExpo->Location = System::Drawing::Point(241, 190);
			this->trackExpo->Maximum = 1000000;
			this->trackExpo->Minimum = 100;
			this->trackExpo->Name = L"trackExpo";
			this->trackExpo->Size = System::Drawing::Size(327, 45);
			this->trackExpo->SmallChange = 500;
			this->trackExpo->TabIndex = 21;
			this->trackExpo->TickFrequency = 1000;
			this->trackExpo->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackExpo->Value = 1000;
			this->trackExpo->Scroll += gcnew System::EventHandler(this, &MainPanel::trackExpo_Scroll);
			// 
			// trackGain
			// 
			this->trackGain->LargeChange = 200;
			this->trackGain->Location = System::Drawing::Point(241, 139);
			this->trackGain->Maximum = 1000;
			this->trackGain->Minimum = 200;
			this->trackGain->Name = L"trackGain";
			this->trackGain->Size = System::Drawing::Size(327, 45);
			this->trackGain->SmallChange = 100;
			this->trackGain->TabIndex = 20;
			this->trackGain->TickFrequency = 100;
			this->trackGain->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackGain->Value = 1000;
			this->trackGain->Scroll += gcnew System::EventHandler(this, &MainPanel::trackGain_Scroll);
			// 
			// trackPhoto
			// 
			this->trackPhoto->LargeChange = 100;
			this->trackPhoto->Location = System::Drawing::Point(241, 55);
			this->trackPhoto->Maximum = 1000;
			this->trackPhoto->Name = L"trackPhoto";
			this->trackPhoto->Size = System::Drawing::Size(327, 45);
			this->trackPhoto->SmallChange = 10;
			this->trackPhoto->TabIndex = 19;
			this->trackPhoto->TickFrequency = 50;
			this->trackPhoto->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackPhoto->Value = 10;
			this->trackPhoto->Scroll += gcnew System::EventHandler(this, &MainPanel::trackPhoto_Scroll);
			// 
			// numGain
			// 
			this->numGain->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numGain->Location = System::Drawing::Point(162, 155);
			this->numGain->Name = L"numGain";
			this->numGain->Size = System::Drawing::Size(45, 27);
			this->numGain->TabIndex = 18;
			this->numGain->Text = L"1000";
			this->numGain->TextChanged += gcnew System::EventHandler(this, &MainPanel::numGain_TextChanged);
			// 
			// numExpo
			// 
			this->numExpo->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numExpo->Location = System::Drawing::Point(162, 198);
			this->numExpo->Name = L"numExpo";
			this->numExpo->Size = System::Drawing::Size(45, 27);
			this->numExpo->TabIndex = 17;
			this->numExpo->Text = L"2000";
			this->numExpo->TextChanged += gcnew System::EventHandler(this, &MainPanel::numExpo_TextChanged);
			// 
			// numPhoto
			// 
			this->numPhoto->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numPhoto->Location = System::Drawing::Point(162, 64);
			this->numPhoto->Name = L"numPhoto";
			this->numPhoto->Size = System::Drawing::Size(45, 27);
			this->numPhoto->TabIndex = 16;
			this->numPhoto->Text = L"10";
			this->numPhoto->TextChanged += gcnew System::EventHandler(this, &MainPanel::numPhoto_TextChanged);
			// 
			// CameraZone
			// 
			this->CameraZone->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CameraZone->Location = System::Drawing::Point(3, 3);
			this->CameraZone->Name = L"CameraZone";
			this->CameraZone->Size = System::Drawing::Size(204, 30);
			this->CameraZone->TabIndex = 15;
			this->CameraZone->Text = L"Camera Parameters";
			this->CameraZone->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Gain
			// 
			this->Gain->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Gain->Location = System::Drawing::Point(15, 157);
			this->Gain->Name = L"Gain";
			this->Gain->Size = System::Drawing::Size(115, 20);
			this->Gain->TabIndex = 12;
			this->Gain->Text = L"Gain";
			this->Gain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ExpoTime
			// 
			this->ExpoTime->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ExpoTime->Location = System::Drawing::Point(15, 200);
			this->ExpoTime->Name = L"ExpoTime";
			this->ExpoTime->Size = System::Drawing::Size(115, 20);
			this->ExpoTime->TabIndex = 4;
			this->ExpoTime->Text = L"Exposure Time";
			this->ExpoTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numFps
			// 
			this->numFps->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numFps->Location = System::Drawing::Point(158, 116);
			this->numFps->Name = L"numFps";
			this->numFps->Size = System::Drawing::Size(115, 20);
			this->numFps->TabIndex = 3;
			this->numFps->Text = L"90";
			// 
			// fps
			// 
			this->fps->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->fps->Location = System::Drawing::Point(15, 115);
			this->fps->Name = L"fps";
			this->fps->Size = System::Drawing::Size(115, 20);
			this->fps->TabIndex = 2;
			this->fps->Text = L"FPS";
			this->fps->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LabelPhoto
			// 
			this->LabelPhoto->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LabelPhoto->Location = System::Drawing::Point(15, 67);
			this->LabelPhoto->Name = L"LabelPhoto";
			this->LabelPhoto->Size = System::Drawing::Size(115, 20);
			this->LabelPhoto->TabIndex = 0;
			this->LabelPhoto->Text = L"#PhotosTaken";
			this->LabelPhoto->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// message
			// 
			this->message->AutoSize = true;
			this->message->Location = System::Drawing::Point(713, 542);
			this->message->Name = L"message";
			this->message->Size = System::Drawing::Size(0, 19);
			this->message->TabIndex = 11;
			// 
			// MainPanel
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1354, 733);
			this->Controls->Add(this->message);
			this->Controls->Add(this->CamPara);
			this->Controls->Add(this->Data);
			this->Controls->Add(this->cameraTake);
			this->Controls->Add(this->piv);
			this->Controls->Add(this->opticalFlow);
			this->Controls->Add(this->imageProcessed);
			this->Controls->Add(this->imageTaken);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->ImageName);
			this->Controls->Add(this->StartCamera);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Name = L"MainPanel";
			this->Text = L"Drop Tracking System";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imageTaken))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imageProcessed))->EndInit();
			this->Data->ResumeLayout(false);
			this->CamPara->ResumeLayout(false);
			this->CamPara->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackExpo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackGain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void StartCamera_Click(System::Object^  sender, System::EventArgs^  e) {
				 frame1 = imread("1.bmp");
				 frame2 = imread("2.bmp");
				 System::IO::FileStream^ imgFile = gcnew System::IO::FileStream("1.bmp", IO::FileMode::Open, IO::FileAccess::Read);
				 imageTaken->Image = System::Drawing::Image::FromStream(imgFile);
				 imageTaken->Refresh();
				 ImageName->Text = "Drop Image";
				 imgFile->Close();
				 
				 finDel = true;

			/*	 
			System::Drawing::Graphics^ graphics = imageProcessed->CreateGraphics();
			System::IntPtr ptr2(frame1.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame1.cols, frame1.rows, frame1.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr2);
			System::Drawing::RectangleF rect(0,0,imageProcessed->Width, imageProcessed->Height);
			graphics->DrawImage(b, rect);
			//imageProcessed->Image = gcnew Bitmap("1.bmp");
			imageProcessed->Refresh();
			delete graphics;
			*/
				 System::String^ numGet = numPhoto->Text;
				ImageName->Text = numGet;

			 }
private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }

private: System::Void opticalFlow_Click(System::Object^  sender, System::EventArgs^  e) {

			 


			 cvtColor(frame1, grayImg1, CV_BGR2GRAY);
			 cvtColor(frame2, grayImg2, CV_BGR2GRAY);
			 
			 if(finDel == true){
				Mat backGround = imread("background.bmp");
				cvtColor(backGround, backGround, COLOR_BGR2GRAY);
			    absdiff(grayImg1, backGround, grayImg1);
				absdiff(grayImg2, backGround, grayImg2);
			 }

			 threshold(grayImg1, grayImg1, 10, 255, THRESH_BINARY);
			 medianBlur(grayImg1, grayImg1,3);
			
			 threshold(grayImg2, grayImg2, 10, 255, THRESH_BINARY);
			 medianBlur(grayImg2, grayImg2,3);
//dilate with larger element so make sure object is nicely visible
			 Mat erodeElement = getStructuringElement( MORPH_RECT,cv::Size(5,5));		
			 Mat dilateElement = getStructuringElement( MORPH_RECT,cv::Size(4,4));
erode(grayImg2,grayImg2,erodeElement);
			 dilate(grayImg2,grayImg2,dilateElement);
			 dilate(grayImg1,grayImg1,dilateElement);

			 
			 erode(grayImg1,grayImg1,erodeElement);

			 searchForObject(grayImg1, dropsOfFrame1, frame1);
			 searchForObject(grayImg2, dropsOfFrame2, frame2);

			 cvtColor(frame1, grayImg1, COLOR_BGR2GRAY);
			cvtColor(frame2, grayImg2, COLOR_BGR2GRAY);

			absdiff(grayImg1, grayImg2, diffImg);
			threshold(diffImg, threshImg, 10, 255, THRESH_BINARY);
			medianBlur(threshImg, threshImg,3);
			cvtColor(threshImg, threshImg, COLOR_GRAY2BGR);

			if(finalImg.empty() == true)
				finalImg = Mat::zeros(threshImg.size(), CV_8UC3);
		/*
			for(int i = 0; i < dropsOfFrame1.size(); i++){
				//putText(threshImg, to_string(i), dropsOfFrame1[i].getPos()+Point(10,0),FONT_HERSHEY_SIMPLEX, 1, Scalar(200,0,200), 2,6, false);
				putText(frame1, to_string(i), dropsOfFrame1[i].getPos(),FONT_HERSHEY_SIMPLEX, 1, Scalar(200,0,200), 2,6, false);
				//putText(orig1, to_string(i), dropsOfFrame1[i].getPos(),FONT_HERSHEY_SIMPLEX, 1, Scalar(200,0,200), 2,6, false);
			}
			for(int i = 0; i < dropsOfFrame2.size(); i++){
				//putText(threshImg, to_string(i), dropsOfFrame2[i].getPos()+Point(10,30),FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 2,6, false);
				putText(frame2, to_string(i), dropsOfFrame2[i].getPos(),FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 2,6, false);
				//putText(orig2, to_string(i), dropsOfFrame2[i].getPos(),FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 2,6, false);
			}
		*/
			Rect objBoundingRect = Rect(0,0,0,0);
			//cout<<"DROPS OF FRAME:  "<<dropsOfFrame1.size()<<endl;
			for(int i = 0; i < dropsOfFrame1.size(); i++){
			//for(int i = 0; i < 4; i++){
				//int x = dropsOfFrame1[i].getXPos();
				//int y = dropsOfFrame1[i].getYPos();
				//cout<<"[x,y]  "<<x<<","<<y<<endl;
				if(dropsOfFrame1[i].getRect().width > dropsOfFrame2[i].getRect().width)
					objBoundingRect = dropsOfFrame1[i].getRect();
				else
					objBoundingRect = dropsOfFrame2[i].getRect();
			
				partImg1 = grayImg1(Range::all(), Range(objBoundingRect.x-objBoundingRect.width,objBoundingRect.x+2*objBoundingRect.width));
				partImg2 = grayImg2(Range::all(), Range(objBoundingRect.x-objBoundingRect.width,objBoundingRect.x+2*objBoundingRect.width));
				//partImg1 = grayImg1;
				//partImg2 = grayImg2;

				/*
				if(partImg1.cols > partImg2.cols){
					partImg1 = partImg1(Range::all(), Range(0,partImg2.cols));
				}else{
					partImg2 = partImg2(Range::all(), Range(0,partImg1.cols));
				}
				*/

				//putText(threshImg, to_string(i), dropsOfFrame1[i].getPos()+Point2i(10,0),FONT_HERSHEY_SIMPLEX, 1, Scalar(200,0,200), 2,6, false);
				//putText(frame1, to_string(i), dropsOfFrame1[i].getPos(),FONT_HERSHEY_SIMPLEX, 1, Scalar(200,0,200), 2,6, false);

				//if(i == 3){
					absdiff(partImg1,partImg2,partImg1);
					//imshow("part", partImg1);
					string name;
					name = "partOut" + to_string(i)+".bmp";
					imwrite(name, partImg1);
				//}
				vector<Point2f> corners;
				vector<Point2f> nextCorners;
				vector<uchar> status;
				vector<float> err;
				//Size windowSize = Size(objBoundingRect.width*0.5, objBoundingRect.height*0.33);//Size(20,10)

				int maxCorner = 100; int minDistance = 10; int blockSize = 5; double qualityLevel = 0.03;
				goodFeaturesToTrack(partImg1, corners, maxCorner , qualityLevel, minDistance, Mat(), blockSize, true);
				calcOpticalFlowPyrLK(partImg1, partImg2, corners, nextCorners, status, err, cv::Size(3,3),4);

				vector<Point2f> goodOldCorners;
				vector<Point2f> goodNewCorners;
				for(int i = 0; i < status.size(); i++){
					if(status[i] == 1){
						goodOldCorners.push_back(corners.at(i));
						goodNewCorners.push_back(nextCorners.at(i));
						//cout<<"Old: "<<corners.at(i)<<endl;
						//cout<<"New: "<<nextCorners.at(i)<<endl;
						//cout<<"------------"<<endl;
					}
				}

			
		
				for(int i = 0; i < goodOldCorners.size(); i++){
					if(goodNewCorners.at(i).y - goodOldCorners.at(i).y > 0){
						line(finalImg, Point2f(objBoundingRect.x-objBoundingRect.width, 0) + goodOldCorners.at(i), Point2f(objBoundingRect.x-objBoundingRect.width, 0) + goodNewCorners.at(i), Scalar(0,0,255));
						circle(finalImg, Point2f(objBoundingRect.x-objBoundingRect.width, 0) + goodOldCorners.at(i), 5, Scalar(0,255,0));
					}
				}
				//imshow("PART", partImg1);
			}
		
		
			add(threshImg, finalImg, finalImg);
			string num = to_string(dropsOfFrame1.size());
			System::String^ text = gcnew System::String(num.c_str());
			numDrops->Text = text;
			numDrops->Refresh();
			for(int i = 0; i < dropsOfFrame1.size(); i++){
				dropChoose->Items->Add(i);
			}

			dropsOfFrame1.clear();
			dropsOfFrame2.clear();
			imwrite("outImg.bmp", finalImg);
			System::IO::FileStream^ imgFile = gcnew System::IO::FileStream("outImg.bmp", IO::FileMode::Open, IO::FileAccess::Read);
			imageProcessed->Image = System::Drawing::Image::FromStream(imgFile);
			imageProcessed->Refresh();
			imgFile->Close();



		 }

private: void searchForObject(Mat frame, vector<Drop>& drops, Mat& drawing2){
	bool objDetected = false;
	Rect objBoundingRect = Rect(0,0,0,0);
	
	vector< vector<cv::Point> > contours;
	vector< Vec4i > hierarchy;
	Mat temp;
	frame.copyTo(temp);
	findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0,0));
	
	vector<RotatedRect> minRect( contours.size() );
	vector<RotatedRect> minEllipse( contours.size() );

	for( int i = 0; i < contours.size(); i++ ){ 
		minRect[i] = minAreaRect( Mat(contours[i]) );
        if( contours[i].size() > 5 ){
			minEllipse[i] = fitEllipse( Mat(contours[i]) );
		}
	}
	Mat drawing = Mat::zeros( temp.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ ){
       //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       // contour
       //drawContours( drawing, contours, i, Scalar(0,255,0), 1, 8, vector<Vec4i>(), 0, Point() );
       // ellipse
       ellipse( drawing, minEllipse[i], Scalar(255,255,255), -1, 8 );
	   //cout<<"Ellipse:"<<minEllipse[i]<<endl;
       // rotated rectangle
       //Point2f rect_points[4]; minRect[i].points( rect_points );
       //for( int j = 0; j < 4; j++ )
       //   line( drawing, rect_points[j], rect_points[(j+1)%4], Scalar(0,255,0), 1, 8 );
    }


	drawing2 = Mat::zeros( temp.size(), CV_8UC3 );
	//drawing.copyTo(drawing2);

	cvtColor(drawing,drawing, COLOR_BGR2GRAY);
	findContours(drawing, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0,0));

	if(hierarchy.size() > 0){
		int numObjects = hierarchy.size();
		//if(numObjects<MAX_NUM_OBJECTS)
		for(int i = 0; i >= 0; i = hierarchy[i][0]){
			Moments moment = moments((cv::Mat)contours[i]);
			double area = moment.m00;
			cout<<"Area"<<area<<endl;

			objBoundingRect = boundingRect(contours[i]);
			if(objBoundingRect.width > objBoundingRect.height)
				swap(objBoundingRect.width,objBoundingRect.height);

			Drop drop;
			drop.setPara(cv::Point(moment.m10/area, moment.m01/area), moment.m10/area, moment.m01/area,area, arcLength(contours[i], true), contours[i], objBoundingRect);
			drops.push_back(drop);
			
			int x = drops[i].getXPos();
			int y = drops[i].getYPos();
			//cout<<"[x,y]  "<<x<<","<<y<<endl;
			//cout<<drop.have_drop<<endl;
			
			drop.have_drop = true;
			objDetected = true;
			

			ellipse(drawing2, cv::Point(x,y), cv::Size(objBoundingRect.width/2, objBoundingRect.height/2), 0, 0, 360, Scalar(255,255,255), -1, 8);


		}

		//subMat = drawing2(Range::all(), Range(objBoundingRect.x-objBoundingRect.width,objBoundingRect.x+2*objBoundingRect.width));

		if(objDetected == true){
			cout<<"YES"<<endl;


		}
	}else{
		Drop no_drop;
		drops.push_back(no_drop);
		cout<<"NO"<<endl;
		

	}
}

private: System::Void piv_Click(System::Object^  sender, System::EventArgs^  e) {
			Mat backGround = imread("background.bmp");
			 cvtColor(backGround, backGround, COLOR_BGR2GRAY);

			 cvtColor(frame1, grayImg1, CV_BGR2GRAY);
			 cvtColor(frame2, grayImg2, CV_BGR2GRAY);
			Mat showImg1, showImg2;
			vector< pair<Point2f, Point2f> > velInfo;
			frame1.copyTo(showImg1);
			frame2.copyTo(showImg2);

			//velInfo = pivProcess(grayImg1, grayImg2);
			velInfo = pivProcess(grayImg1, grayImg2, dropsOfFrame1);
			int countAvg = 0;
			double avgX = 0, avgY = 0;
			for(int i = 0; i < velInfo.size(); i++){
				drawVec(velInfo[i].first, velInfo[i].second, showImg1);

				if(abs(velInfo[i].second.y*60) > 11){
					avgY += velInfo[i].second.y*60;
					avgX += velInfo[i].second.x*60;
					countAvg++;
				}
			}
			avgX /= countAvg;
			avgY /= countAvg;
			add(showImg2, showImg1, showImg1);
			imwrite("pivImg.bmp", showImg1);
			System::IO::FileStream^ imgFile = gcnew System::IO::FileStream("pivImg.bmp", IO::FileMode::Open, IO::FileAccess::Read);
			imageProcessed->Image = System::Drawing::Image::FromStream(imgFile);
			imageProcessed->Refresh();
			imgFile->Close();
		 }

private: vector< pair<Point2f, Point2f> > pivProcess(Mat frame1, Mat frame2, vector<Drop> drops){
	vector< pair<Point2f, Point2f> > ptInfo;
	pair<Point2f, Point2f> tmpPair;
	Point2f tmpVec;
	//int blockSize = 16;
	//cout<<frame1.size()<<endl;
	for(int i = 0; i < drops.size(); i++){
		int blockSizeW = drops[i].getRect().width;
		int blockSizeH = drops[i].getRect().height;

		Mat block1 = Mat::zeros(cvSize(blockSizeW, blockSizeH), CV_64F);
		//block1 = frame1(Range(y, y+blockSize),Range(x, x+blockSize));
		block1 = frame1(Range(drops[i].getYPos()-blockSizeH/2, drops[i].getYPos()+blockSizeH/2), Range(drops[i].getXPos()-blockSizeW/2, drops[i].getXPos()+blockSizeW/2));
		//cout<<block1.size()<<endl;
	//////
	for(int x = 0; x+block1.cols < frame1.cols; x = x+block1.cols){
		for(int y = 0; y+block1.rows < frame1.rows; y = y+block1.rows){
			//Mat block1 = Mat::zeros(Size(blockSize, blockSize), CV_64F);
			Mat block2 = Mat::zeros(cvSize(block1.rows, block1.cols), CV_64F);
			//block1 = frame1(Range(y, y+blockSize),Range(x, x+blockSize));
			block2 = frame2(Range(y, y+block1.rows),Range(x, x+block1.cols));
			//cout<<x<<","<<y<<endl;
			//cout<<block2.size()<<endl;
			tmpPair.first.x = x + blockSizeW/2;
			tmpPair.first.y = y + blockSizeH/2;
			tmpVec = fftcc(block1, block2);
			tmpPair.second.x = tmpVec.x;
			tmpPair.second.y = tmpVec.y;
			ptInfo.push_back(tmpPair);

		}
	}
	///////

	}
	return ptInfo;
}

private: Point2f fftcc(Mat block1, Mat block2){
	Point2f pt;
	Mat dst1 = Mat::zeros(block1.size(), CV_64F);
	Mat dst2 = Mat::zeros(block2.size(), CV_64F);
	//convertScaleAbs(block1, dst1, 1.0, 0.0);
	//convertScaleAbs(block2, dst2, 1.0, 0.0);
	normalize(block1, dst1, 0, 1, CV_MINMAX);
	normalize(block2, dst2, 0, 1, CV_MINMAX);
	pt = PIVCorr(dst1, dst2, true);
	pt.x = block1.cols/2 - pt.x;
	pt.y = block2.rows/2 - pt.y;
	return pt;
}

private: Point2f PIVCorr(Mat dst1, Mat dst2, bool subPixel){
	Point2i minLoc = Point2i(0,0);
	Point2i maxLoc = Point2i(0,0);
	Point2f maxSubLoc = Point2f(0.0, 0.0);

	int optM = getOptimalDFTSize(dst1.rows);
	int optN = getOptimalDFTSize(dst1.cols);

	//cout<<dst1.rows<<","<<dst1.cols<<endl;
	//cout<<dst2.rows<<","<<dst2.cols<<endl;
	//cout<<optM<<","<<optN<<endl;
	//cout<<optM - dst1.rows<<endl;
	//cout<<optN - dst1.cols<<endl;
	Mat F, G;
	
	copyMakeBorder(dst1, F, 0, optM - dst1.rows, 0, optN - dst1.cols, BORDER_CONSTANT, Scalar::all(0));
	copyMakeBorder(dst2, G, 0, optM - dst2.rows, 0, optN - dst2.cols, BORDER_CONSTANT, Scalar::all(0));

	normalize(F, F, 0, 1, CV_MINMAX);
	normalize(G, G, 0, 1, CV_MINMAX);

	Mat planes1[] = {Mat_<double>(F), Mat::zeros(F.size(), CV_64F)};
	Mat planes2[] = {Mat_<double>(G), Mat::zeros(G.size(), CV_64F)};
	
	Mat complexImg1, complexImg2;
	merge(planes1, 2, complexImg1);
	merge(planes2, 2, complexImg2);

	dft(complexImg1, complexImg1, CV_DXT_MUL_CONJ);
	dft(complexImg2, complexImg2, CV_DXT_MUL_CONJ);

	Mat mul;
	mulSpectrums(complexImg1, complexImg2, mul, CV_DXT_MUL_CONJ);
	dft(mul, mul, CV_DXT_INVERSE_SCALE);
	split(mul, planes1);
	//split(complexImg1, planes1);
	//split(complexImg2, planes2);
	Mat imgRe = Mat::zeros(F.size(), CV_64F);
	imgRe = abs(planes1[0]);

	//shift DFT, so that the origin is at the image center
	int cx = imgRe.cols/2;
	int cy = imgRe.rows/2;

	Mat q0(imgRe, Rect(0,0,cx,cy));
	Mat q1(imgRe, Rect(cx,0,cx,cy));
	Mat q2(imgRe, Rect(0,cy,cx,cy));
	Mat q3(imgRe, Rect(cx,cy,cx,cy));

	swap(q0,q3);
	swap(q1,q2);
	normalize(imgRe, imgRe, 0, 1, CV_MINMAX);

	double m = 0;
	double M = 0;
	double val = 0;
	double second = 0;
	double tmp = 0;	
	double max = 0;

	minMaxLoc(imgRe, &m, &M, &minLoc, &maxLoc);
	//cout<<imgRe.size()<<endl;
	//cout<<imgRe.at<double>(0,10)<<endl;
//cout<<"123"<<endl;
	for(int i = 0; i < imgRe.rows; i++){
		for(int j = 0; j < imgRe.cols; j++){
			//cout<<"qq"<<i<<","<<j<<endl;
			val = imgRe.at<double>(i,j);
			if(val > second){
				tmp = second;
				second = val;
				if(second > max){
					max = second;
					second = tmp;
					maxLoc.y = i;
					maxLoc.x = j;
				}
			}

		}
	}
	
	if(subPixel){
		double if1 = 0;
		double f0 = 0;
		double f1 = 0;
		double dx = 0;
		double dy = 0;
		if(maxLoc.x - 1 < 0 || maxLoc.x + 1 > imgRe.cols - 1){
			maxSubLoc.x = maxLoc.x;
	
		}else{
		
			if1 = imgRe.at<double>(maxLoc.y, maxLoc.x-1);
			f0 = imgRe.at<double>(maxLoc.y, maxLoc.x);
			f1 = imgRe.at<double>(maxLoc.y, maxLoc.x+1);
			dx = (f1 - if1)/(2*(2*f0 - if1 - f1));
			if(dx < -1 || dx >1)
				dx = 0;
			maxSubLoc.x = maxLoc.x + dx;
		}
		
		if(maxLoc.y - 1 < 0 || maxLoc.y + 1 > imgRe.rows - 1){
			maxSubLoc.y = maxLoc.y;
	
		}else{
	
			if1 = imgRe.at<double>(maxLoc.y - 1, maxLoc.x);
	
			f0 = imgRe.at<double>(maxLoc.y, maxLoc.x);
		
			f1 = imgRe.at<double>(maxLoc.y+1, maxLoc.x);
			
			dy = (f1 - if1)/(2*(2*f0 - if1 - f1));
		
			if(dy < -1 || dy >1){
				dy = 0;
			
			}
			maxSubLoc.y = maxLoc.y + dy;
		}
		
	}else{
		maxSubLoc.x = maxLoc.x;
		maxSubLoc.y = maxLoc.y;
	}
	//std var 
	double mmr = 0;
	double snr = 0;
	vector<double> avg;
	vector<double> std;
	double ppr = 0;
	meanStdDev(imgRe, avg, std);
	mmr = max/avg[0];
	snr = (max - mmr)/std[0];
	ppr = max/second;

	if(mmr<1.2 || ppr<1 || second == max){
		maxSubLoc.x = dst1.cols/2;
		maxSubLoc.y = dst1.rows/2;
	}
	
	return maxSubLoc;
}

private: void drawVec(Point2f pos, Point2f vec, Mat& img){
	int amp = 1;
	Point2f pEnd(pos.x + amp* vec.x, pos.y + amp*vec.y);
	Scalar lineColor(0,255,255);
	drawArrow(img, pos, vec, pEnd);
}

private: void drawArrow(Mat& img, Point2f pos, Point2f vec, Point2f pEnd){
	const double PI = 3.1415926;
	Point2f arrow;
	//int len = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	int len = 5;
	if(norm(pos - pEnd) >= 1){
		double angle = atan2((double)(pos.y - pEnd.y), (double)(pos.x - pEnd.x));
		line(img, pos, pEnd, Scalar(255,0,255));
		arrow.x = pEnd.x + len* cos(angle + PI*45/180);
		arrow.y = pEnd.y + len* sin(angle + PI*45/180);
		line(img, pEnd, arrow, Scalar(255,0,255));
		arrow.x = pEnd.x + len* cos(angle - PI*45/180);
		arrow.y = pEnd.y + len* sin(angle - PI*45/180);
		line(img, pEnd, arrow, Scalar(255,0,255));
	}

}

//-----------------------------------------------------------------------------------------------------------//
private: System::Void cameraTake_Click(System::Object^  sender, System::EventArgs^  e) {
			 Mat imgTaken;
			 uint32_t c_countOfImagesToGrab = uint32_t::Parse(numPhoto->Text);
			 string fileName;
			 int cnt = 0;
			 PylonAutoInitTerm autoInitTerm;
			 try
			 {
					const uint32_t cWidth = 659;
					const uint32_t cHeight = 494;
					const uint32_t cPadding = 10;
					const uint8_t cSampleGrayValue = 160;

					//CInstantCamera camera( CTlFactory::GetInstance().CreateFirstDevice());
					Camera_t camera(CTlFactory::GetInstance().CreateFirstDevice());
					camera.Open();
					UserSetDefaultSelectorEnums oldDefaultUserSet = camera.UserSetDefaultSelector.GetValue();

					/*
					camera.GainAuto.SetValue(GainAuto_Off);
					camera.GainRaw.SetValue(500);
					camera.ExposureAuto.SetValue(ExposureAuto_Off);
					camera.ExposureTimeRaw.SetValue(1000);
					*/
					int gainNum = int::Parse(numGain->Text);
					int expoNum = int::Parse(numExpo->Text);
					camera.GainAuto.SetValue(GainAuto_Off);
					camera.GainRaw.SetValue(gainNum);
					camera.ExposureAuto.SetValue(ExposureAuto_Off);
					camera.ExposureTimeRaw.SetValue(expoNum);

					string gainStr = to_string(camera.ExposureTimeRaw.GetValue()) +"::" + to_string(camera.ExposureTimeAbs.GetValue())+  "::" + to_string(camera.GainRaw.GetValue());//;
					System::String^ numGet =gcnew System::String(gainStr.c_str());
					ImageName->Text = numGet;
					

					camera.MaxNumBuffer = 5;

					camera.StartGrabbing( c_countOfImagesToGrab);
					//camera.StartGrabbing( GrabStrategy_OneByOne, GrabLoop_ProvidedByInstantCamera);

					CGrabResultPtr ptrGrabResult;
					uchar *pImageBuffer;
					//vector<uchar> imgBuffer;

					while ( camera.IsGrabbing())
					{
						// Wait for an image and then retrieve it. A timeout of 5000 ms is used.
						camera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);

						// Image grabbed successfully?
						if (ptrGrabResult->GrabSucceeded())
						{
							// message->Text = .ToString();
							// Access the image data.
							pImageBuffer = (uchar *) ptrGrabResult->GetBuffer();


							//fileName2 = "takenByPy.bmp";
							//CImagePersistence::Save( ImageFileFormat_Bmp, fileName2, ptrGrabResult);

							imgTaken = Mat::zeros( cv::Size(659,494), CV_8UC1 );
							//cout << "Gray value of first pixel: " << (uint32_t) pImageBuffer[0] << endl << endl;
							for(int i = 0; i < 659*494; i++){
								imgTaken.at<uchar>(i) = (uchar) pImageBuffer[i];
							}

							fileName = "taken" + to_string(cnt) + ".bmp";
							imwrite(fileName, imgTaken);
							waitKey(1);
							System::String^ file = gcnew System::String(fileName.c_str());
							System::IO::FileStream^ imgFile = gcnew System::IO::FileStream(file, IO::FileMode::Open, IO::FileAccess::Read);
							imageTaken->Image = System::Drawing::Image::FromStream(imgFile);
							imageTaken->Refresh();
							imgFile->Close();
							cnt++;
							
						}
						else
						{
							//cout << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
							ImageName->Text = "Error: Cannot Grab Images";
						}
					}

					ptrGrabResult.Release();
					
					camera.StopGrabbing();
					camera.Close();

			 }catch (GenICam::GenericException &e){
				 ImageName->Text = "Error: Cannot Connect to the Camera";
				 
			 }
			 
			 
			 numFrame->Text = c_countOfImagesToGrab.ToString();
			 frameChoose->Items->Clear();
			 for(int i = 0; i < c_countOfImagesToGrab; i++){
				frameChoose->Items->Add(i);
			 }

			
			 

		 }


private: System::Void dropChoose_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int numClick = dropChoose->SelectedIndex;
			 //string num = to_string(dropsOfFrame1[numClick].getArea());
			 //System::String^ text = gcnew System::String(num.c_str());
			 System::String^ text = dropsOfFrame1.size().ToString();
			 numArea->Text = text;
			 numArea->Refresh();

			 //num = to_string(norm(dropsOfFrame1[numClick].getPos()-dropsOfFrame2[numClick].getPos()));
			 //num = to_string(dropsOfFrame2.size());
			 //text = gcnew System::String(num.c_str());
			 //numDist->Text = text;
			// numDist->Refresh();
		 }


private: System::Void frameChoose_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int numClick = frameChoose->SelectedIndex;
			 System::String^ file = "taken" + numClick.ToString() + ".bmp";
			 System::IO::FileStream^ imgFile = gcnew System::IO::FileStream(file, IO::FileMode::Open, IO::FileAccess::Read);
			 imageTaken->Image = System::Drawing::Image::FromStream(imgFile);
			 imageTaken->Refresh();
			 imgFile->Close();

			 numClick++;
			 file = "taken" + numClick.ToString() + ".bmp";
			 imgFile = gcnew System::IO::FileStream(file, IO::FileMode::Open, IO::FileAccess::Read);
			 imageProcessed->Image = System::Drawing::Image::FromStream(imgFile);
			 imageProcessed->Refresh();
			 imgFile->Close();
			 //////////////////////////////////////////////////////change String^ file to string type and add numClick/////
			 //int numClick = frameChoose->SelectedIndex;
			 numClick--;
			 string file1 = "taken";
			 frame1 = imread(file1 + to_string(numClick) + ".bmp");
			 frame2 = imread(file1 + to_string(numClick++) + ".bmp");
			 finDel = false;
			 //////////////////////////////////////////////////////
		 }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void trackPhoto_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 //message->Text = trackPhoto->Value.ToString();
			 numPhoto->Text = trackPhoto->Value.ToString();
		 }
private: System::Void numPhoto_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 trackPhoto->Value = int::Parse(numPhoto->Text);
		 }
private: System::Void trackGain_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 numGain->Text = trackGain->Value.ToString();
		 }
private: System::Void numGain_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 trackGain->Value = int::Parse(numGain->Text);
		 }
private: System::Void trackExpo_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 numExpo->Text = trackExpo->Value.ToString();
		 }
private: System::Void numExpo_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 trackExpo->Value = int::Parse(numExpo->Text);
		 }
};
}
