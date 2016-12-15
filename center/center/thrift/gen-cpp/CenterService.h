/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef CenterService_H
#define CenterService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "center_types.h"

namespace center {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class CenterServiceIf {
 public:
  virtual ~CenterServiceIf() {}
  virtual void report_monitor_info(const MonitorInfo& mi) = 0;
};

class CenterServiceIfFactory {
 public:
  typedef CenterServiceIf Handler;

  virtual ~CenterServiceIfFactory() {}

  virtual CenterServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(CenterServiceIf* /* handler */) = 0;
};

class CenterServiceIfSingletonFactory : virtual public CenterServiceIfFactory {
 public:
  CenterServiceIfSingletonFactory(const boost::shared_ptr<CenterServiceIf>& iface) : iface_(iface) {}
  virtual ~CenterServiceIfSingletonFactory() {}

  virtual CenterServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(CenterServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<CenterServiceIf> iface_;
};

class CenterServiceNull : virtual public CenterServiceIf {
 public:
  virtual ~CenterServiceNull() {}
  void report_monitor_info(const MonitorInfo& /* mi */) {
    return;
  }
};

typedef struct _CenterService_report_monitor_info_args__isset {
  _CenterService_report_monitor_info_args__isset() : mi(false) {}
  bool mi :1;
} _CenterService_report_monitor_info_args__isset;

class CenterService_report_monitor_info_args {
 public:

  CenterService_report_monitor_info_args(const CenterService_report_monitor_info_args&);
  CenterService_report_monitor_info_args& operator=(const CenterService_report_monitor_info_args&);
  CenterService_report_monitor_info_args() {
  }

  virtual ~CenterService_report_monitor_info_args() throw();
  MonitorInfo mi;

  _CenterService_report_monitor_info_args__isset __isset;

  void __set_mi(const MonitorInfo& val);

  bool operator == (const CenterService_report_monitor_info_args & rhs) const
  {
    if (!(mi == rhs.mi))
      return false;
    return true;
  }
  bool operator != (const CenterService_report_monitor_info_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CenterService_report_monitor_info_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CenterService_report_monitor_info_pargs {
 public:


  virtual ~CenterService_report_monitor_info_pargs() throw();
  const MonitorInfo* mi;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CenterService_report_monitor_info_result {
 public:

  CenterService_report_monitor_info_result(const CenterService_report_monitor_info_result&);
  CenterService_report_monitor_info_result& operator=(const CenterService_report_monitor_info_result&);
  CenterService_report_monitor_info_result() {
  }

  virtual ~CenterService_report_monitor_info_result() throw();

  bool operator == (const CenterService_report_monitor_info_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CenterService_report_monitor_info_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CenterService_report_monitor_info_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CenterService_report_monitor_info_presult {
 public:


  virtual ~CenterService_report_monitor_info_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CenterServiceClient : virtual public CenterServiceIf {
 public:
  CenterServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CenterServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void report_monitor_info(const MonitorInfo& mi);
  void send_report_monitor_info(const MonitorInfo& mi);
  void recv_report_monitor_info();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CenterServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<CenterServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CenterServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_report_monitor_info(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CenterServiceProcessor(boost::shared_ptr<CenterServiceIf> iface) :
    iface_(iface) {
    processMap_["report_monitor_info"] = &CenterServiceProcessor::process_report_monitor_info;
  }

  virtual ~CenterServiceProcessor() {}
};

class CenterServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CenterServiceProcessorFactory(const ::boost::shared_ptr< CenterServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CenterServiceIfFactory > handlerFactory_;
};

class CenterServiceMultiface : virtual public CenterServiceIf {
 public:
  CenterServiceMultiface(std::vector<boost::shared_ptr<CenterServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CenterServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CenterServiceIf> > ifaces_;
  CenterServiceMultiface() {}
  void add(boost::shared_ptr<CenterServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void report_monitor_info(const MonitorInfo& mi) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->report_monitor_info(mi);
    }
    ifaces_[i]->report_monitor_info(mi);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class CenterServiceConcurrentClient : virtual public CenterServiceIf {
 public:
  CenterServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CenterServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void report_monitor_info(const MonitorInfo& mi);
  int32_t send_report_monitor_info(const MonitorInfo& mi);
  void recv_report_monitor_info(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
