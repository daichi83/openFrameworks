#pragma once

#include "ofConstants.h"
#include "ofTexture.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofBaseVideoGrabber.h"

#ifdef OF_VIDEO_CAPTURE_DIRECTSHOW
	#include "videoInput.h"
#endif


class ofDirectShowGrabber : public ofBaseVideoGrabber{

	public :

		ofDirectShowGrabber();
		virtual ~ofDirectShowGrabber();

		void 			listDevices();
		bool			initGrabber(int w, int h);
		void			grabFrame();

		void			videoSettings();
		void			close();
		
		void			clearMemory();
		
		unsigned char	* getPixels();
		bool			isFrameNew();

		float			getWidth();
		float			getHeight();

		void			setVerbose(bool bTalkToMe);
		void			setDeviceID(int _deviceID);
		void			setDesiredFrameRate(int framerate);
		

	protected:
	
		bool					bChooseDevice;
		int						deviceID;
		bool 					bVerbose;
		bool 					bGrabberInited;
	    unsigned char * 		pixels;
		int						attemptFramerate;
		bool 					bIsFrameNew;	
		
		int						width, height;	
		//--------------------------------- directshow
		#ifdef OF_VIDEO_CAPTURE_DIRECTSHOW
			int 					device;
			videoInput 				VI;
			bool 					bDoWeNeedToResize;
		#endif	
};
