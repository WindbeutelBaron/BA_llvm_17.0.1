//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14
// TODO: Change to XFAIL once https://github.com/llvm/llvm-project/issues/40340 is fixed
// UNSUPPORTED: availability-pmr-missing

// <list>

// namespace std::pmr {
// template <class T>
// using list =
//     ::std::list<T, polymorphic_allocator<T>>
//
// } // namespace std::pmr

#include <list>
#include <memory_resource>
#include <type_traits>
#include <cassert>

int main(int, char**) {
  using StdList = std::list<int, std::pmr::polymorphic_allocator<int>>;
  using PmrList = std::pmr::list<int>;
  static_assert(std::is_same<StdList, PmrList>::value, "");
  PmrList d;
  assert(d.get_allocator().resource() == std::pmr::get_default_resource());

  return 0;
}
