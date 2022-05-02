 class VerifyClockTime(CafyEvent):
        """
        Event to Manipulate and verify clock time
        """
        def __init__(self, ntp_obj, inv_obj, tftp_server, retries=10, delay=20, interval=30, **kwargs):
            self.tftp_server = tftp_server
            self.inv_obj = inv_obj
            self.ntp = ntp_obj
            self.retries = retries
            self.delay = delay
            self.interval = interval
        def launch(self):
            """
            Launch event to manipulate clock time
            :return:
            """
            self.current_times = self.ntp.get_clock_detail()
            self.current_time = datetime.datetime.strptime(self.current_times[0].time_stamp,
                                                    "%H:%M:%S.%f %Z %a %b %d %Y")
            self.date = random.choice(range(1,29))
            month = random.choice(['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'])
            # self.ntp.set_clock_time(str(self.c