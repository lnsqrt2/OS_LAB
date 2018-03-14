asmlinkage int sys_mycopy(void)
{
	int i = 0;
	int r_fp, w_fp;
	char buffer[1024];

	mm_segment_t fs;
	fs = get_fs();
	set_fs(get_ds());
	
	r_fp = sys_open("/home/lumos/FileRead.txt",O_RDONLY,0);
	if(r_fp == -1)
	{
		return -1;
	}
	w_fp = sys_open("/home/lumos/FileWrite.txt",O_WRONLY|O_CREAT|O_TRUNC,0600);
	if(w_fp == -1)
	{
		return -1;
	}

	if(r_fp>0&&w_fp>0)
	{
		do
		{
			i = sys_read(r_fp,buffer,1024);
			sys_write(w_fp,buffer,i);
		}
		while(i);
	}

	sys_close(r_fp);
	sys_close(w_fp);
	set_fs(fs);
	return 0;
}