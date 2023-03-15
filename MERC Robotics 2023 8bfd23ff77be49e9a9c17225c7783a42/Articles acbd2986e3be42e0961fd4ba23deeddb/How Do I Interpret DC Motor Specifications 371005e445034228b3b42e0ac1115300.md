# How Do I Interpret DC Motor Specifications?

Choosing the right [DC Motor](https://www.robotshop.com/collections/dc-motors) (or [DC gear motor](https://www.robotshop.com/collections/spur-gearmotors)) for a specific application can be a daunting task and many manufacturers only provide basic motor specifications. These basic specifications might not be sufficient for your needs. Listed below are ideal motor specifications and whenever possible, ways to approximate values.

### **Nominal Voltage**

The voltage corresponds to the highest motor efficiency. Try to choose a main battery pack that most closely matches the nominal voltage of your drive motors. For example, if the motor's nominal voltage is 6V, use a 5x 1.2V NiMh pack to get 6V. If your motor operates at 3.5V nominal, you can use either a 3xAA or 3xAAA NiMh pack or a 3.7V LiPo or LiIon pack. If you operate a motor outside of its nominal voltage, the efficiency of the motor goes down, often requiring additional current, generating more heat, and decreasing the lifespan of the motor. Aside from a "nominal voltage" DC motors also have an operating voltage range outside of which the manufacturer does not suggest operating the motor. For example, a 6V DC Gear motor may have an operating range of 3-9V; it will not operate as efficiently as compared to 6V, but it will still run well.

### **No Load RPM**

This is how fast (angular velocity) the final output shaft will rotate assuming nothing is connected to it. If the motor has a gear down and the motor's speed is not indicated separately, the no-load rpm value is the shaft speed after the gear down. The motor’s RPM is proportional to the voltage input. “No Load” means the motor encounters no resistance whatsoever (no hub or wheel mounted to the end). Usually, the No Load RPM provided is associated with the nominal voltage.

### **Power Rating**

If a motor's power is not listed, it can be approximated. Power is related to current (I) and voltage (V) by the equation P = I*V. Use the no-load current and nominal voltage to approximate the motor's power output. The motor's maximum power (which should only be used for a short time) can be approximated using the stall current and nominal voltage (rather than maximum voltage).

### **Stall Torque**

This is the maximum torque* a motor can provide with the shaft no longer rotating. It is important to note that most motors will sustain irreparable damage if subjected to stall conditions for more than a few seconds. When choosing a motor, you should consider subjecting it to no more than ~1/4 to 1/3 the stall torque.

### **Stall Current**

This is the current the motor will draw under maximum torque* conditions. This value can be very high and should you not have a motor controller capable of providing this current, there is a good chance your electronics will fry as well. If neither the stall nor the nominal current is provided, try to use the motor's power rating (in Watts) and the nominal voltage to estimate the current: Power [Watts] = Voltage [Volts] x Current [Amps]

### **General Specifications**

A DC motor's general specifications usually include weight, shaft length, and shaft diameter as well as motor length and diameter. Other useful dimensions include the location of mounting holes and thread type. If only the length or diameter is provided, refer to an image, photo, or scale drawing to get a sense of the other dimensions based on the one known value.

### **Torque**

"Torque" is calculated by multiplying a force (acting at a distance away from a pivot) by the distance. A motor rated at a stall torque of 10Nm can hold 10N at the end of 1m. Similarly, it could also hold 20N at the end of 0.5m (20 x 0.50 = 10) and so on. **Note**: 1 Kg * force of gravity (9.81m/s2) = 9.81N (~10N for quick calculations)

![https://community.robotshop.com/uploads/c/b/cbenson/imported/Torque-simple.gif](https://community.robotshop.com/uploads/c/b/cbenson/imported/Torque-simple.gif)

### **Voltage vs. RPM**

Ideally, the manufacturer would list the graph of a motor's voltage vs. rpm. For a quick approximation, consider using the no-load rpm and nominal voltage: (nominal voltage, rpm) and the point (0, 0). See “gear down” below for motors with gear down.

### **Torque vs. Current**

Current is a value that cannot be easily controlled. DC motors use only as much current as they need. Ideal specifications include this curve, and approximations are not easily reproduced. The stall torque is related to the stall current. A motor that is prevented from turning will consume the maximum (“stall”) current and produce the maximum torque possible. The current required to provide a given torque is based on many factors including the thickness, type, and configuration of the wires used to make the motor, the magnets, and other mechanical factors.

### **Technical specifications or 3D CAD drawing**

Many robot builders like to draw their robots on the computer before purchasing the necessary parts. Although all motor manufacturers have a CAD drawing with the dimensions, they rarely make it available to the public. Ideal motor dimensions include the basics listed above, as well as mounting hole locations and thread type. Ideally, the materials used to make the motor, gears and winding as well as separate dimensions for the motor and the gear down would also be given.

### **Gear Down**

DC motor manufacturers that also produce the corresponding gear down for a motor must list the gear down ratio. The gear down acts to increase torque and reduce rpm. The No Load RPM value given is always that of the last output shaft after the gear is down. To find the angular velocity of the motor shaft before the gear down, multiply the value by the gear ratio. To obtain the motor's stall torque before the gear down, divide the stall torque by the gear down. The material used to make the internal gears is usually plastic or metal and is chosen to be able to withstand the maximum torque rating. Calculate the gear down below given the values before and after gear down:

![https://community.robotshop.com/uploads/c/b/cbenson/imported/Optical-encoder-simple.gif](https://community.robotshop.com/uploads/c/b/cbenson/imported/Optical-encoder-simple.gif)

**Accessories**: An [optical encoder](https://www.robotshop.com/home/products/Robot-Parts/Sensors/Encoders-and-Disks/index.html) is the most common accessory for a gear motor. Finding the right size of an optical encoder for your motor can be very difficult if it is not made by the same company. An optical encoder allows you to track both the direction of rotation and the number of revolutions of the motor. With the right code, an optical encoder can also give you the angle of the shaft.

### **Hubs and Shaft Couplers**

Secondary items such as [hubs](https://www.robotshop.com/home/products/Robot-Parts/Mechanics/Sensor-Wheel-and-Motor-Mounts/index.html) (used to connect the output shaft to other items) are slowly becoming available for varying-sized output shafts. Only a few manufacturers provide generic shaft couplers. If you cannot find the appropriate coupler, consider using spur gears to offset the shaft to that of a different size. The image below shows three different types of couplers. The hole in the hub is for a threaded screw (“set screw”) which presses tightly against the shaft.

![https://community.robotshop.com/uploads/c/b/cbenson/imported/Shaft-coupler-simple.gif](https://community.robotshop.com/uploads/c/b/cbenson/imported/Shaft-coupler-simple.gif)