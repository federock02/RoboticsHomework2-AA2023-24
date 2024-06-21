define model
(
  name "scout_mini"
  pose [0.0 0.0 0.0 0.0]

  # Base properties
  size [0.612 0.580 0.245]
  origin [0.0 0.0 0.0 0.0]
  drive "diff"
  color "gray"

  # Wheel properties
  wheel_radius 0.08

  # Laser sensor
  sensor(
    name "scan"
    pose [0 0 0.1 0]
    range [0 6.5]
    samples 640
    fov 120.0
    color "black"
    size [ 0.06 0.15 0.03 ]
  )

  # Visual properties
  gui_nose 0.15
)