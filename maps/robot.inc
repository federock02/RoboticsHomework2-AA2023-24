define scout_mini model
(
  name "scout_mini"
  size [0.612 0.580 0.245]  # Dimensions in meters
  origin [0.0 0.0 0.1225 0.0]  # Set the origin at the center of the height (x, y, z)

  # Define the color and appearance
  color "black"

  # Motors and driving parameters
  plugin "libstageplugin"
  (
    # Model type and parameters
    model "scout_mini"
    robottype "differential"
    
    # Mechanical dimensions and other parameters
    drive "diff"
    (
      wheels 4
      wheel_radius 0.08  # Assuming the wheel radius is 80mm as not specified in the image
      wheel_base 0.580  # Distance between front and rear wheels
      track_width 0.490  # Distance between left and right wheels
    )

    # Physical dimensions of the robot
    size [0.612 0.580 0.245]  # Length, width, height

    # Mobility parameters
    max_speed 3.0  # Maximum speed in m/s
    max_payload 10.0  # Maximum payload in kg

    # Obstacle clearance
    obstacle_clearance 0.115  # Clearance in meters (115mm)
  )
)
