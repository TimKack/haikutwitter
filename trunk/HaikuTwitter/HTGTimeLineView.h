/*
 * Copyright 2010 Martin Hebnes Pedersen, martinhpedersen @ "google mail"
 * All rights reserved. Distributed under the terms of the MIT License.
 */ 

#include "ListView.h"
#include "ScrollView.h"
#include "TabView.h"

#include <string>
#include <sstream>

#ifdef INFOPOPPER_SUPPORT
#include <infopopper/InfoPopper.h>
#include <infopopper/IPMessage.h>
#include <infopopper/IPConnection.h>
#endif

#include "TimeLineParser.h"
#include "SearchParser.h"
#include "twitcurl/twitcurl.h"
#include "HTTweet.h"
#include "HTGTweetItem.h"
#include "HTGInfoPopperSettingsWindow.h"

#ifndef HTG_TIMELINEVIEW_H
#define HTG_TIMELINEVIEW_H

const int32 TIMELINE_HOME = 'HOME';
const int32 TIMELINE_FRIENDS = 'TML';
const int32 TIMELINE_MENTIONS = 'MNTN';
const int32 TIMELINE_PUBLIC = 'PBLC';
const int32 TIMELINE_USER = 'TUSR';
const int32 TIMELINE_SEARCH = 'TSCH';

status_t updateTimeLineThread(void *data);

class HTGTimeLineView : public BView {
public:
	HTGTimeLineView(twitCurl *, const int32, BRect, const char * requestInfo = " ");
	void updateTimeLine();
	void AttachedToWindow();
	~HTGTimeLineView();
	
//private:
	void sendNotificationFor(HTTweet *theTweet);
	int32 getSearchID();
	void setSearchID(int32 id);
	void savedSearchDestoySelf();
	void savedSearchCreateSelf();
	bool _retrieveInfoPopperBoolFromSettings();
	bool waitingForUpdate;
	bool wantsNotifications;
	BListView *listView;
	BList *unhandledList;
	BScrollView *theScrollView;
	
	thread_id previousThread;
	
	int32 searchID;
	TimeLineParser *timeLineParser;
	twitCurl *twitObj;
	int32 TYPE;
	
	std::string& htmlFormatedString(const char *orig);
};
#endif
