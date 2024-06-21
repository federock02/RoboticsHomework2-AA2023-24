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
    robottype "omnidirectional"
    
    # Mechanical dimensions and other parameters
    drive "diff"
    (
      wheels 4
      wheel_radius 0.1  # Estimate
      wheel_base 0.451
      track_width 0.490
      suspension "independent"
    )

    # Motors and driving parameters
    motor
    (
      type "dc_brushless"
      power 150  # in Watts
      quantity 4
    )

    battery
    (
      type "lithium"
      voltage 24  # in Volts
      capacity 15  # in Ah
    )

    # Performance and other parameters
    performance
    (
      max_speed 10.0  # km/h
      min_turning_radius 0.0  # meters
      max_gradeability 30.0  # degrees
      ground_clearance 0.115  # meters
      max_endurance 8.0  # hours
      max_travel 10.0  # km
      charging_time 2.0  # hours
      working_temp [-10.0 40.0]  # degrees Celsius
      ip_grade "IP22"
    )

    control
    (
      mode "remote"
      interface "CAN"
      remote_distance 200.0  # meters
    )
  )
)
