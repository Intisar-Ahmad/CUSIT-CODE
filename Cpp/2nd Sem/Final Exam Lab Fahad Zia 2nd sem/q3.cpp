#include <iostream>

using namespace std;

class MediaPlayer{
    public:
    virtual void play(){
        cout << "Played by MediaPlayer" << endl;
    }

    virtual void stop(){
        cout << "Stopped by MediaPlayer" << endl;
    }

};


class AudioPlayer : public MediaPlayer{
    public:
    void play() override{
        cout << "Playing audio track" << endl;
    }

    void stop() override{
        cout << "Stopping audio playback" << endl;
    }
};  
class VideoPlayer : public MediaPlayer{
    public:
    void play() override{
        cout << "Playing video file" << endl;
    }
    
    void stop() override{
        cout << "Stopping video playback" << endl;
    }
    
};
class StreamingPlayer : public MediaPlayer{
    public:
    void play() override{
        cout << "Streaming content online" << endl;
    }
    
    void stop() override{
        cout << "Ending stream session" << endl;
    }

};

int main() {
    MediaPlayer* audio = new AudioPlayer();
    MediaPlayer* video = new VideoPlayer();
    MediaPlayer* stream = new StreamingPlayer();
    

    (*audio).play();
    audio->stop();
    video->play();
    video->stop();
    stream->play();
    stream->stop();
    return 0;
}