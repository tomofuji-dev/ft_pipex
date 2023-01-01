/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/08 01:33:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAG_H
# define FT_PRINTF_FLAG_H

# include <wchar.h>
# include <stdint.h>
# include <stddef.h>

# define TFLAG_C		0x008000
# define TFLAG_UI		0x900004
# define TFLAG_DBL		0xa00000
# define TFLAG_E		0x080000
# define TFLAG_G		0xa20000
# define TFLAG_LL		0x920008
# define TFLAG_ULL		0x900008
# define TFLAG_DEC		0x900a00
# define TFLAG_HEX		0x901000
# define TFLAG_OCT		0x900800
# define TFLAG_CAP		0x010000
# define TYPE_LITERAL	0x308000
# define TYPE_C			0x508000
# define TYPE_S			0x608000
# define TYPE_P			0x301008
# define TYPE_D			0x920a00
# define TYPE_U			0x900a00
# define TYPE_X			0x901000
# define TYPE_O			0x900800
# define TYPE_F			0xa40a00
# define TYPE_E			0xa80a00
# define TYPE_G			0xae0a00
# define TYPE_A			0xa41000
# define TYPE_N			0x310104
# define TMASK_LEN		0x0000ff
# define FLAG_LEFT		0x002
# define FLAG_ZERO		0x004
# define FLAG_ALT		0x008
# define FLAG_PLUS		0x010
# define FLAG_SPACE		0x020
# define FLAG_DIGIT		0x040
# define FLAG_PRECISION	0x080

#endif
