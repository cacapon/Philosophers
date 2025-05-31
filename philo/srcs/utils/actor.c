/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 09:11:22 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"

// startがいる
//

// ? どうやってtell->actor.msgboxにアクセスできるだろう?
// typedef struct s_actor_ref
// {
// 	void	(*tell)(t_msg msg);
// 	void	(*stop)(void);
// }			t_actor_ref;

// static void	_actor_loop(void *args)
// {
// }

// // スレッドを走らせる
// // 無限ループで待つmsgbox受信待機関数を動かす。
// // メッセージがあったらカスタムのon_recieveにmsgを渡す
// t_actor_ref	*actor_start(void *args)
// {
// 	pthread_t th;

// 	pthread_create(&th, NULL, _actor_loop, args);
// 	pthread_detach(&th);
// }