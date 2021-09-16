# space_concordia_training

The node written in C++ publishes a 'string' type message ("hello, world") to a topic repeatedly at a defined rate.

The node written in Python suscribes to the topic. Once a message is received, the callback function just print out whatever the received message.
