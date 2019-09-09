#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int v_start_start = ofGetFrameNum();
	for (int v_start = v_start_start; v_start < v_start_start + 360; v_start += 20) {

		vector<glm::vec3> vertices_1, vertices_2, vertices_3;
		for (int v = v_start; v < v_start + 15; v++) {

			int u = v * 6;

			vertices_1.push_back(this->make_point(300, 80, u, v));
			vertices_2.push_back(this->make_point(300, 80, u + 120, v));
			vertices_3.push_back(this->make_point(300, 80, u + 240, v));
		}

		ofNoFill();

		ofSetColor(255, 0, 0);
		ofBeginShape();
		ofVertices(vertices_1);
		ofEndShape();

		ofSetColor(0, 255, 0);
		ofBeginShape();
		ofVertices(vertices_2);
		ofEndShape();

		ofSetColor(0, 0, 255);
		ofBeginShape();
		ofVertices(vertices_3);
		ofEndShape();

		ofFill();

		ofSetColor(255, 0, 0);
		ofDrawSphere(vertices_1.back(), 8);
		ofSetColor(0, 255, 0);
		ofDrawSphere(vertices_2.back(), 8);
		ofSetColor(0, 0, 255);
		ofDrawSphere(vertices_3.back(), 8);
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}