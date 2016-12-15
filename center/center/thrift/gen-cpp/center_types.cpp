/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "center_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace center {


MonitorInfo::~MonitorInfo() throw() {
}


void MonitorInfo::__set_m_monitor_id(const int32_t val) {
  this->m_monitor_id = val;
}

void MonitorInfo::__set_m_ip(const std::string& val) {
  this->m_ip = val;
}

void MonitorInfo::__set_m_usage_ratio(const double val) {
  this->m_usage_ratio = val;
}

uint32_t MonitorInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->m_monitor_id);
          this->__isset.m_monitor_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->m_ip);
          this->__isset.m_ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->m_usage_ratio);
          this->__isset.m_usage_ratio = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MonitorInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MonitorInfo");

  xfer += oprot->writeFieldBegin("m_monitor_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->m_monitor_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("m_ip", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->m_ip);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("m_usage_ratio", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->m_usage_ratio);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MonitorInfo &a, MonitorInfo &b) {
  using ::std::swap;
  swap(a.m_monitor_id, b.m_monitor_id);
  swap(a.m_ip, b.m_ip);
  swap(a.m_usage_ratio, b.m_usage_ratio);
  swap(a.__isset, b.__isset);
}

MonitorInfo::MonitorInfo(const MonitorInfo& other0) {
  m_monitor_id = other0.m_monitor_id;
  m_ip = other0.m_ip;
  m_usage_ratio = other0.m_usage_ratio;
  __isset = other0.__isset;
}
MonitorInfo& MonitorInfo::operator=(const MonitorInfo& other1) {
  m_monitor_id = other1.m_monitor_id;
  m_ip = other1.m_ip;
  m_usage_ratio = other1.m_usage_ratio;
  __isset = other1.__isset;
  return *this;
}
void MonitorInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MonitorInfo(";
  out << "m_monitor_id=" << to_string(m_monitor_id);
  out << ", " << "m_ip=" << to_string(m_ip);
  out << ", " << "m_usage_ratio=" << to_string(m_usage_ratio);
  out << ")";
}

} // namespace
