import QtQuick
import QtLocation
import QtPositioning
import QtQuick.Controls
import QtMultimedia 5.15
import QtMultimedia



Item {
    id:rectan
    width: 200
    height: 200
    //color: "black"
    state: "PhotoCapture"

    property string platformScreen: ""
    property int buttonsPanelLandscapeWidth: 328
    property int buttonsPanelPortraitHeight: 180



    states: [
        State {
            name: "PhotoCapture"
            StateChangeScript {
                script: {
                    camera.start()
                }
            }
        }
    ]

    CaptureSession {
        id: captureSession
        camera: Camera {
            id: camera
        }

        videoOutput: viewfinder
    }



    VideoOutput {
        id: viewfinder
        visible: ((cameraUI.state === "PhotoCapture") || (cameraUI.state === "VideoCapture"))
        width: 200
        height: 200
        //        autoOrientation: true
    }


}
