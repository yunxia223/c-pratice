#pragma once
#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
#include "speaker.h"

using namespace std;

class SpeechManager {
public:
	SpeechManager();
	void show_Menu();
	void exitSystem();
	void initSpeech();
	void createSpeaker();
	void startSpeech();
	void speechDraw();
	void speechContest();
	void saveRecord();
	void loadRecord();
	
	bool fileIsEmpty;
	map<int, vector<string>>m_Record;
	void showScore();
	void showRecord();
	~SpeechManager();

	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;
	map<int, Speaker>m_Speaker;
	int m_Index;
};
