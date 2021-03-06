#pragma once

#include "ofMain.h"
#include "recon/SensorFactory.h"
#include "of-pcl-bridge/of-pcl-bridge.h"
#include "PointCloudWriter.h"
#include <ofxGui.h>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		std::list<recon::AbstractSensor::Ptr> sensor_list_;
		std::map<int, ofTexture> sensor_images_;
		
		PointCloudWriter writer_;

		std::vector<ofRectangle> imageLayout_;

		ofxPanel ui_;
		ofxToggle record_;
};
