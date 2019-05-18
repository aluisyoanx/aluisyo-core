// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2018 The Circle Foundation
// Copyright (c) 2019 Aluisyo
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <System/Dispatcher.h>

namespace System {

class ContextGroup {
public:
  explicit ContextGroup(Dispatcher& dispatcher);
  ContextGroup(const ContextGroup&) = delete;
  ContextGroup(ContextGroup&& other);
  ~ContextGroup();
  ContextGroup& operator=(const ContextGroup&) = delete;
  ContextGroup& operator=(ContextGroup&& other);
  void interrupt();
  void spawn(std::function<void()>&& procedure);
  void wait();

private:
  Dispatcher* dispatcher;
  NativeContextGroup contextGroup;
};

}
