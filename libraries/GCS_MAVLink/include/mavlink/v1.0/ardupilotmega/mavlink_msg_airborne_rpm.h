// MESSAGE AIRBORNE_RPM PACKING

#define MAVLINK_MSG_ID_AIRBORNE_RPM 227

typedef struct __mavlink_airborne_rpm_t
{
 uint16_t RPM[8]; ///<  RPM sensor array
} mavlink_airborne_rpm_t;

#define MAVLINK_MSG_ID_AIRBORNE_RPM_LEN 16
#define MAVLINK_MSG_ID_227_LEN 16

#define MAVLINK_MSG_ID_AIRBORNE_RPM_CRC 166
#define MAVLINK_MSG_ID_227_CRC 166

#define MAVLINK_MSG_AIRBORNE_RPM_FIELD_RPM_LEN 8

#define MAVLINK_MESSAGE_INFO_AIRBORNE_RPM { \
	"AIRBORNE_RPM", \
	1, \
	{  { "RPM", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_airborne_rpm_t, RPM) }, \
         } \
}


/**
 * @brief Pack a airborne_rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param RPM  RPM sensor array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_airborne_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AIRBORNE_RPM_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#else
	mavlink_airborne_rpm_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AIRBORNE_RPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
}

/**
 * @brief Pack a airborne_rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param RPM  RPM sensor array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_airborne_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AIRBORNE_RPM_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#else
	mavlink_airborne_rpm_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AIRBORNE_RPM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
}

/**
 * @brief Encode a airborne_rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param airborne_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_airborne_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_airborne_rpm_t* airborne_rpm)
{
	return mavlink_msg_airborne_rpm_pack(system_id, component_id, msg, airborne_rpm->RPM);
}

/**
 * @brief Encode a airborne_rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param airborne_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_airborne_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_airborne_rpm_t* airborne_rpm)
{
	return mavlink_msg_airborne_rpm_pack_chan(system_id, component_id, chan, msg, airborne_rpm->RPM);
}

/**
 * @brief Send a airborne_rpm message
 * @param chan MAVLink channel to send the message
 *
 * @param RPM  RPM sensor array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_airborne_rpm_send(mavlink_channel_t chan, const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AIRBORNE_RPM_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
#else
	mavlink_airborne_rpm_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, (const char *)&packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, (const char *)&packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_AIRBORNE_RPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_airborne_rpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, buf, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
#else
	mavlink_airborne_rpm_t *packet = (mavlink_airborne_rpm_t *)msgbuf;

	mav_array_memcpy(packet->RPM, RPM, sizeof(uint16_t)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, (const char *)packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN, MAVLINK_MSG_ID_AIRBORNE_RPM_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRBORNE_RPM, (const char *)packet, MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE AIRBORNE_RPM UNPACKING


/**
 * @brief Get field RPM from airborne_rpm message
 *
 * @return  RPM sensor array
 */
static inline uint16_t mavlink_msg_airborne_rpm_get_RPM(const mavlink_message_t* msg, uint16_t *RPM)
{
	return _MAV_RETURN_uint16_t_array(msg, RPM, 8,  0);
}

/**
 * @brief Decode a airborne_rpm message into a struct
 *
 * @param msg The message to decode
 * @param airborne_rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_airborne_rpm_decode(const mavlink_message_t* msg, mavlink_airborne_rpm_t* airborne_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_airborne_rpm_get_RPM(msg, airborne_rpm->RPM);
#else
	memcpy(airborne_rpm, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AIRBORNE_RPM_LEN);
#endif
}
