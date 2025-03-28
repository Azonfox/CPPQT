import QtQuick
import QtQuick.Window
import QtQuick3D
import QtQuick3D.Helpers

Window {
    width: 800
    height: 600
    visible: true
    title: "Куб, вращающийся по X, Y, Z"
    color: "#222222"

    View3D {
        anchors.fill: parent

        environment: SceneEnvironment {
            clearColor: "#222222"
            backgroundMode: SceneEnvironment.Color
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        // Камера с небольшим наклоном для лучшего обзора
        PerspectiveCamera {
            position: Qt.vector3d(0, 100, 500)
            eulerRotation.x: -15
        }

        // Освещение
        DirectionalLight {
            eulerRotation.x: -30
            eulerRotation.y: 30
            brightness: 1.2
        }

        // Вращающийся куб
        Model {
            id: cube
            position: Qt.vector3d(0, 0, 0)
            scale: Qt.vector3d(1.5, 1.5, 1.5)
            source: "#Cube"

            materials: PrincipledMaterial {
                baseColor: "lightcoral"  // Красный цвет
                metalness: 0.5
                roughness: 0.3
                specularAmount: 0.8
            }

            // Анимация вращения по X
            PropertyAnimation on eulerRotation.x {
                from: 0
                to: 360
                duration: 6000
                loops: Animation.Infinite
            }

            // Анимация вращения по Y
            PropertyAnimation on eulerRotation.y {
                from: 0
                to: 360
                duration: 8000
                loops: Animation.Infinite
            }

            // Анимация вращения по Z
            PropertyAnimation on eulerRotation.z {
                from: 0
                to: 360
                duration: 5000
                loops: Animation.Infinite
            }
        }

        // Оси координат (для наглядности)
        AxisHelper {
            scale: Qt.vector3d(2, 2, 2)
        }
    }
}
