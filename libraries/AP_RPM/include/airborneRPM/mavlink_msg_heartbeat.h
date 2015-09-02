// MESSAGE HEARTBEAT PACKING

#define MAVLINK_MSG_ID_HEARTBEAT 0

typedef struct __mavlink_heartbeat_t
{
 uint16_t RPM[8]; /*<  RPM sensor array*/
} mavlink_heartbeat_t;

#define MAVLINK_MSG_ID_HEARTBEAT_LEN 16
#define MAVLINK_MSG_ID_0_LEN 16

#define MAVLINK_MSG_ID_HEARTBEAT_CRC 61
#define MAVLINK_MSG_ID_0_CRC 61

#define MAVLINK_MSG_HEARTBEAT_FIELD_RPM_LEN 8

#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
	"HEARTBEAT", \
	1, \
	{  { "RPM", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_heartbeat_t, RPM) }, \
         } \
}


/**
 * @brief Pack a heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param RPM  RPM sensor array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
	mavlink_heartbeat_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param RPM  RPM sensor array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
	mavlink_heartbeat_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
}

/**
 * @brief Encode a heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
	return mavlink_msg_heartbeat_pack(system_id, component_id, msg, heartbeat->RPM);
}

/**
 * @brief Encode a heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
	return mavlink_msg_heartbeat_pack_chan(system_id, component_id, chan, msg, heartbeat->RPM);
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param RPM  RPM sensor array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heartbeat_send(mavlink_channel_t chan, const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
#else
	mavlink_heartbeat_t packet;

	mav_array_memcpy(packet.RPM, RPM, sizeof(uint16_t)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *RPM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_uint16_t_array(buf, 0, RPM, 8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
#else
	mavlink_heartbeat_t *packet = (mavlink_heartbeat_t *)msgbuf;

	mav_array_memcpy(packet->RPM, RPM, sizeof(uint16_t)*8);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE HEARTBEAT UNPACKING


/**
 * @brief Get field RPM from heartbeat message
 *
 * @return  RPM sensor array
 */
static inline uint16_t mavlink_msg_heartbeat_get_RPM(const mavlink_message_t* msg, uint16_t *RPM)
{
	return _MAV_RETURN_uint16_t_array(msg, RPM, 8,  0);
}

/**
 * @brief Decode a heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_heartbeat_decode(const mavlink_message_t* msg, mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_heartbeat_get_RPM(msg, heartbeat->RPM);
#else
	memcpy(heartbeat, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif
}
