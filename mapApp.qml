import QtQuick 2.12
import QtQuick.Controls 2.12
import QtLocation 5.11

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "地图信息"

    Map {
        id: map
        anchors.fill: parent

        // 设置地图中心坐标为 Oslo
        center {
            latitude: 59.9485
            longitude: 10.7686
        }

        // 设置地图缩放级别，zoomLevel范围为 0 到 maximumZoomLevel
        zoomLevel: 10

        // 使用 MapType 选择不同的地图类型（卫星地图、普通地图等）
        plugin: Plugin {
            name: "osm"  // 这里使用 OpenStreetMap 插件
        }
    }

    // signal qmlClick();

    // function onCppClick()
    // {
    //     console.log("this is qml: cpp's click")
    // }

    Rectangle {
        width: parent.width
        height: 50
        color: "#f0f0f0"
        anchors.top: parent.top

        TextField {
            id: latInput
            width: parent.width / 2
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            placeholderText: "输入纬度"
        }

        TextField {
            id: lonInput
            width: parent.width / 2
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            placeholderText: "输入经度"
        }

        Button {
            text: "更新位置"
            anchors.top: latInput.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                var lat = parseFloat(latInput.text)
                var lon = parseFloat(lonInput.text)
                map.center = QtPositioning.coordinate(lat, lon)
                // qmlClick()
            }
        }
    }
}
