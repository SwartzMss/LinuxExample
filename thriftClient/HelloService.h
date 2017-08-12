/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef HelloService_H
#define HelloService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "hello_types.h"

namespace test {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class HelloServiceIf {
 public:
  virtual ~HelloServiceIf() {}
  virtual void hello(std::string& _return, const std::string& username) = 0;
};

class HelloServiceIfFactory {
 public:
  typedef HelloServiceIf Handler;

  virtual ~HelloServiceIfFactory() {}

  virtual HelloServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(HelloServiceIf* /* handler */) = 0;
};

class HelloServiceIfSingletonFactory : virtual public HelloServiceIfFactory {
 public:
  HelloServiceIfSingletonFactory(const boost::shared_ptr<HelloServiceIf>& iface) : iface_(iface) {}
  virtual ~HelloServiceIfSingletonFactory() {}

  virtual HelloServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(HelloServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<HelloServiceIf> iface_;
};

class HelloServiceNull : virtual public HelloServiceIf {
 public:
  virtual ~HelloServiceNull() {}
  void hello(std::string& /* _return */, const std::string& /* username */) {
    return;
  }
};

typedef struct _HelloService_hello_args__isset {
  _HelloService_hello_args__isset() : username(false) {}
  bool username :1;
} _HelloService_hello_args__isset;

class HelloService_hello_args {
 public:

  HelloService_hello_args(const HelloService_hello_args&);
  HelloService_hello_args& operator=(const HelloService_hello_args&);
  HelloService_hello_args() : username() {
  }

  virtual ~HelloService_hello_args() throw();
  std::string username;

  _HelloService_hello_args__isset __isset;

  void __set_username(const std::string& val);

  bool operator == (const HelloService_hello_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    return true;
  }
  bool operator != (const HelloService_hello_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloService_hello_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloService_hello_pargs {
 public:


  virtual ~HelloService_hello_pargs() throw();
  const std::string* username;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloService_hello_result__isset {
  _HelloService_hello_result__isset() : success(false) {}
  bool success :1;
} _HelloService_hello_result__isset;

class HelloService_hello_result {
 public:

  HelloService_hello_result(const HelloService_hello_result&);
  HelloService_hello_result& operator=(const HelloService_hello_result&);
  HelloService_hello_result() : success() {
  }

  virtual ~HelloService_hello_result() throw();
  std::string success;

  _HelloService_hello_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const HelloService_hello_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const HelloService_hello_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloService_hello_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloService_hello_presult__isset {
  _HelloService_hello_presult__isset() : success(false) {}
  bool success :1;
} _HelloService_hello_presult__isset;

class HelloService_hello_presult {
 public:


  virtual ~HelloService_hello_presult() throw();
  std::string* success;

  _HelloService_hello_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class HelloServiceClient : virtual public HelloServiceIf {
 public:
  HelloServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HelloServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void hello(std::string& _return, const std::string& username);
  void send_hello(const std::string& username);
  void recv_hello(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class HelloServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<HelloServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (HelloServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_hello(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  HelloServiceProcessor(boost::shared_ptr<HelloServiceIf> iface) :
    iface_(iface) {
    processMap_["hello"] = &HelloServiceProcessor::process_hello;
  }

  virtual ~HelloServiceProcessor() {}
};

class HelloServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  HelloServiceProcessorFactory(const ::boost::shared_ptr< HelloServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< HelloServiceIfFactory > handlerFactory_;
};

class HelloServiceMultiface : virtual public HelloServiceIf {
 public:
  HelloServiceMultiface(std::vector<boost::shared_ptr<HelloServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~HelloServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<HelloServiceIf> > ifaces_;
  HelloServiceMultiface() {}
  void add(boost::shared_ptr<HelloServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void hello(std::string& _return, const std::string& username) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hello(_return, username);
    }
    ifaces_[i]->hello(_return, username);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class HelloServiceConcurrentClient : virtual public HelloServiceIf {
 public:
  HelloServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HelloServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void hello(std::string& _return, const std::string& username);
  int32_t send_hello(const std::string& username);
  void recv_hello(std::string& _return, const int32_t seqid);
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
