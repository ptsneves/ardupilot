// MESSAGE RPM PACKING

#define MAVLINK_MSG_ID_RPM 226

typedef struct __mavlink_rpm_t
{
 float rpm1; ///< RPM Sensor1
 float rpm2; ///< RPM Sensor2
 float rpm3; ///< RPM Sensor3
 float rpm4; ///< RPM Sensor4
 float rpm5; ///< RPM Sensor5
 float rpm6; ///< RPM Sensor6
 float rpm7; ///< RPM Sensor7
 float rpm8; ///< RPM Sensor8
} mavlink_rpm_t;

#define MAVLINK_MSG_ID_RPM_LEN 32
#define MAVLINK_MSG_ID_226_LEN 32

#define MAVLINK_MSG_ID_RPM_CRC 50
#define MAVLINK_MSG_ID_226_CRC 50



#define MAVLINK_MESSAGE_INFO_RPM { \
	"RPM", \
	8, \
	{  { "rpm1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rpm_t, rpm1) }, \
         { "rpm2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rpm_t, rpm2) }, \
         { "rpm3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rpm_t, rpm3) }, \
         { "rpm4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rpm_t, rpm4) }, \
         { "rpm5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_rpm_t, rpm5) }, \
         { "rpm6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_rpm_t, rpm6) }, \
         { "rpm7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_rpm_t, rpm7) }, \
         { "rpm8", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_rpm_t, rpm8) }, \
         } \
}


/**
 * @brief Pack a rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rpm1 RPM Sensor1
 * @param rpm2 RPM Sensor2
 * @param rpm3 RPM Sensor3
 * @param rpm4 RPM Sensor4
 * @param rpm5 RPM Sensor5
 * @param rpm6 RPM Sensor6
 * @param rpm7 RPM Sensor7
 * @param rpm8 RPM Sensor8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float rpm1, float rpm2, float rpm3, float rpm4, float rpm5, float rpm6, float rpm7, float rpm8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_LEN];
	_mav_put_float(buf, 0, rpm1);
	_mav_put_float(buf, 4, rpm2);
	_mav_put_float(buf, 8, rpm3);
	_mav_put_float(buf, 12, rpm4);
	_mav_put_float(buf, 16, rpm5);
	_mav_put_float(buf, 20, rpm6);
	_mav_put_float(buf, 24, rpm7);
	_mav_put_float(buf, 28, rpm8);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_LEN);
#else
	mavlink_rpm_t packet;
	packet.rpm1 = rpm1;
	packet.rpm2 = rpm2;
	packet.rpm3 = rpm3;
	packet.rpm4 = rpm4;
	packet.rpm5 = rpm5;
	packet.rpm6 = rpm6;
	packet.rpm7 = rpm7;
	packet.rpm8 = rpm8;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RPM_LEN);
#endif
}

/**
 * @brief Pack a rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm1 RPM Sensor1
 * @param rpm2 RPM Sensor2
 * @param rpm3 RPM Sensor3
 * @param rpm4 RPM Sensor4
 * @param rpm5 RPM Sensor5
 * @param rpm6 RPM Sensor6
 * @param rpm7 RPM Sensor7
 * @param rpm8 RPM Sensor8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float rpm1,float rpm2,float rpm3,float rpm4,float rpm5,float rpm6,float rpm7,float rpm8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_LEN];
	_mav_put_float(buf, 0, rpm1);
	_mav_put_float(buf, 4, rpm2);
	_mav_put_float(buf, 8, rpm3);
	_mav_put_float(buf, 12, rpm4);
	_mav_put_float(buf, 16, rpm5);
	_mav_put_float(buf, 20, rpm6);
	_mav_put_float(buf, 24, rpm7);
	_mav_put_float(buf, 28, rpm8);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_LEN);
#else
	mavlink_rpm_t packet;
	packet.rpm1 = rpm1;
	packet.rpm2 = rpm2;
	packet.rpm3 = rpm3;
	packet.rpm4 = rpm4;
	packet.rpm5 = rpm5;
	packet.rpm6 = rpm6;
	packet.rpm7 = rpm7;
	packet.rpm8 = rpm8;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RPM_LEN);
#endif
}

/**
 * @brief Encode a rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rpm_t* rpm)
{
	return mavlink_msg_rpm_pack(system_id, component_id, msg, rpm->rpm1, rpm->rpm2, rpm->rpm3, rpm->rpm4, rpm->rpm5, rpm->rpm6, rpm->rpm7, rpm->rpm8);
}

/**
 * @brief Encode a rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rpm_t* rpm)
{
	return mavlink_msg_rpm_pack_chan(system_id, component_id, chan, msg, rpm->rpm1, rpm->rpm2, rpm->rpm3, rpm->rpm4, rpm->rpm5, rpm->rpm6, rpm->rpm7, rpm->rpm8);
}

/**
 * @brief Send a rpm message
 * @param chan MAVLink channel to send the message
 *
 * @param rpm1 RPM Sensor1
 * @param rpm2 RPM Sensor2
 * @param rpm3 RPM Sensor3
 * @param rpm4 RPM Sensor4
 * @param rpm5 RPM Sensor5
 * @param rpm6 RPM Sensor6
 * @param rpm7 RPM Sensor7
 * @param rpm8 RPM Sensor8
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rpm_send(mavlink_channel_t chan, float rpm1, float rpm2, float rpm3, float rpm4, float rpm5, float rpm6, float rpm7, float rpm8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_LEN];
	_mav_put_float(buf, 0, rpm1);
	_mav_put_float(buf, 4, rpm2);
	_mav_put_float(buf, 8, rpm3);
	_mav_put_float(buf, 12, rpm4);
	_mav_put_float(buf, 16, rpm5);
	_mav_put_float(buf, 20, rpm6);
	_mav_put_float(buf, 24, rpm7);
	_mav_put_float(buf, 28, rpm8);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_LEN);
#endif
#else
	mavlink_rpm_t packet;
	packet.rpm1 = rpm1;
	packet.rpm2 = rpm2;
	packet.rpm3 = rpm3;
	packet.rpm4 = rpm4;
	packet.rpm5 = rpm5;
	packet.rpm6 = rpm6;
	packet.rpm7 = rpm7;
	packet.rpm8 = rpm8;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)&packet, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)&packet, MAVLINK_MSG_ID_RPM_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float rpm1, float rpm2, float rpm3, float rpm4, float rpm5, float rpm6, float rpm7, float rpm8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, rpm1);
	_mav_put_float(buf, 4, rpm2);
	_mav_put_float(buf, 8, rpm3);
	_mav_put_float(buf, 12, rpm4);
	_mav_put_float(buf, 16, rpm5);
	_mav_put_float(buf, 20, rpm6);
	_mav_put_float(buf, 24, rpm7);
	_mav_put_float(buf, 28, rpm8);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_LEN);
#endif
#else
	mavlink_rpm_t *packet = (mavlink_rpm_t *)msgbuf;
	packet->rpm1 = rpm1;
	packet->rpm2 = rpm2;
	packet->rpm3 = rpm3;
	packet->rpm4 = rpm4;
	packet->rpm5 = rpm5;
	packet->rpm6 = rpm6;
	packet->rpm7 = rpm7;
	packet->rpm8 = rpm8;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)packet, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)packet, MAVLINK_MSG_ID_RPM_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RPM UNPACKING


/**
 * @brief Get field rpm1 from rpm message
 *
 * @return RPM Sensor1
 */
static inline float mavlink_msg_rpm_get_rpm1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field rpm2 from rpm message
 *
 * @return RPM Sensor2
 */
static inline float mavlink_msg_rpm_get_rpm2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field rpm3 from rpm message
 *
 * @return RPM Sensor3
 */
static inline float mavlink_msg_rpm_get_rpm3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field rpm4 from rpm message
 *
 * @return RPM Sensor4
 */
static inline float mavlink_msg_rpm_get_rpm4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field rpm5 from rpm message
 *
 * @return RPM Sensor5
 */
static inline float mavlink_msg_rpm_get_rpm5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field rpm6 from rpm message
 *
 * @return RPM Sensor6
 */
static inline float mavlink_msg_rpm_get_rpm6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field rpm7 from rpm message
 *
 * @return RPM Sensor7
 */
static inline float mavlink_msg_rpm_get_rpm7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field rpm8 from rpm message
 *
 * @return RPM Sensor8
 */
static inline float mavlink_msg_rpm_get_rpm8(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a rpm message into a struct
 *
 * @param msg The message to decode
 * @param rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_rpm_decode(const mavlink_message_t* msg, mavlink_rpm_t* rpm)
{
#if MAVLINK_NEED_BYTE_SWAP
	rpm->rpm1 = mavlink_msg_rpm_get_rpm1(msg);
	rpm->rpm2 = mavlink_msg_rpm_get_rpm2(msg);
	rpm->rpm3 = mavlink_msg_rpm_get_rpm3(msg);
	rpm->rpm4 = mavlink_msg_rpm_get_rpm4(msg);
	rpm->rpm5 = mavlink_msg_rpm_get_rpm5(msg);
	rpm->rpm6 = mavlink_msg_rpm_get_rpm6(msg);
	rpm->rpm7 = mavlink_msg_rpm_get_rpm7(msg);
	rpm->rpm8 = mavlink_msg_rpm_get_rpm8(msg);
#else
	memcpy(rpm, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RPM_LEN);
#endif
}
