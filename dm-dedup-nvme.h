#include <linux/types.h>

struct nvme_passthru_kv_cmd {
	__u8  opcode;
	__u8  flags;
	__u16 rsvd1;
	__u32 nsid;
	__u32 cdw2;
	__u32 cdw3;
	__u32 cdw4;
	__u32 cdw5;
	__u64 data_addr;
	__u32 data_len;
	__u32 key_len;
	__u32 cdw10;
	__u32 cdw11;
	union {
		struct {
			__u64 key_addr;
			__u32 rsvd5;
			__u32 rsvd6;
		};
		__u8  key[16];
		struct {
			__u32 cdw12;
			__u32 cdw13;
			__u32 cdw14;
			__u32 cdw15;
		};
	};
	__u32 timeout_ms;
	__u32 result;
	__u32 status;
	__u32 ctxid;
	__u32 reqid;
};

#define NVME_IOCTL_IO_KV_CMD    _IOWR('N', 0x51, struct nvme_passthru_kv_cmd)

enum nvme_opcode {
	nvme_cmd_kv_store = 0x81,
	nvme_cmd_kv_append = 0x83,
	nvme_cmd_kv_retrieve = 0x90,
	nvme_cmd_kv_delete = 0xA1,
	nvme_cmd_kv_iter_req = 0xB1,
	nvme_cmd_kv_iter_read = 0xB2,
	nvme_cmd_kv_exist = 0xB3,
	nvme_cmd_kv_decrease = 0xB4,
};