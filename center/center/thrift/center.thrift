namespace cpp center

struct MonitorInfo{
    1:i32 m_monitor_id,
    2:string m_ip,
    3:double m_usage_ratio,
}

service CenterService{
    void report_monitor_info(1:MonitorInfo mi),
}
